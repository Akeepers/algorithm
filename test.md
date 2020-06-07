实现参考ACL 2019, Exploring Pre-trained Language Models for Event Extraction and Generation 

##Trigger Extractor  

**实现方法**：利用bert/ernie等pretrain-model编码输入文本word-level的语义表示，再对每个token做多分类 
**评估**：连续的token被预测为相同的label，则将整个span作为一个label

##Arguments Extractor

**实现方式**：
1. 对每种类别的argument做span prediction。如ACE05-ee数据集中总共35种arguments，则对每种arguments都会预测当前token是否是span的起始位置，最终每个token做70类别的**多标签分类任务**。
2. 利用bert/ernie等pretrain-model编码输入文本的语义表示，trigger（触发词）的位置信息也会加入（将预训练模型用来区分输入句子的segmentembedding，trigger对应位置被设为1。如ernie中的text_type_ids, bert中的segment_ids)

**评估**：
遍历所有的argument类别进行评估，对于每种argument：

1. 从左至右遍历输入文本的每个预测值，若当前token预测为start span，则将当前位置作为start span candidate，继续向右，若遇到预测为end span的位置，转到2；若遇到另一个预测为start span的位置，比较和当前start span candidate的概率大小，较大的被作为新的start span candidate
2. (start span candidate, end span candidate)作为一个预测值，**仅span的起始位置和arguments 类别均和golden label一致时，预测正确**，然后转到1

Note：由于sub word算法，部分英文单词会被分成以'##'开头的subtoken，subtoken被预测为start/end span时，会将span起始位置映射回原始token的位置，则同一token的不同subtoken 都被预测为start span, 仅算一次

## 结论
1. PMLEE论文结果不可复现（论文本身的问题）,对argument做span extraction的方式有可取之处，trigger extractor的方法相对常规；如果希望继续提升该方案的结果，建议从trigger extractor入手
2. argument extractor中的类似tf-idf方式从而给loss分配weight的方式很难说通，且实验无效果，即使论文中的结果提升也较少（0.5），最终模型中去除
3. 数据增强：论文中评估函数的公式存在错误，按思路自己修正后，加入生成数据并不能提升模型的效果，反而会下降，该方案不采用

## 部分尝试过的方案：
1. 在做argument抽取时，将event_type以mrc的形式加入（即作为text_b, 原始样本作为text_a），在单独的argument extractor任务上有提升（证明event type作为先验知识对结果有提升）；联合评估时无提升（猜测是因为pipeline方式的错误传递）
2. 联合训练：共享了ernie的参数，结果变差，**怀疑**是因为每个batch，两个任务对encoder的输入不同导致。

    实现方案：trigger和argument的训练样本数不一致, trigger较多, 则按比例重设argument extractor的batch_size（往往不能整除，会对argument 的样本随机采样，加入当前epoch的训练样本中，从而使得一个epoch两个任务的train step相同），一个epoch内，两个任务的所有训练样本都至少输入模型一次
3. trick：无效果

    评估/预测的时候，如果subtoken被预测为了start/end ,都会将其转化为原来完整token的index -> 那么一个token 的golden label是start/end index，只需要经过subword 算法得到的subtoken有一个预测正确，那么结果也是正确的。如果把所有的subtoken都设为原始token 的gold label -> 那么模型原来是希望第一个subtoken被预测对，现在就是希望有subtoken预测对就可以，这样会不会有效果

## 结果
联合评估是最终结果，分阶段的结果是单个任务的结果，数据参考 数据预处理 部分


## 部分实验设置
### 数据预处理
trigger extractor和argument extractor分开训练，train/dev/test构建方式如下（trigger extractor是常规的多分类任务，略）：

1. argument extractor：仅保留样本中存在事件的样本，若一个样本包含多个事件，则拆分，保证train/dev/test集合中每个样本有且仅有一个事件

