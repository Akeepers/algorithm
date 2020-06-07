m = pow(10, 7)
i = 2
res = [0, 1]
while i * i < m:
    res.append(i * i)
    i += 1
res=[str(x) for x in res]
s = ','.join(res)
with open('h.txt', 'w') as fw:
    fw.write(s)
