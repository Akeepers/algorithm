/*
 * @Author: yangpan
 * @Date: 2020-02-17 12:53:56
 * @LastEditors  : yangpan
 * @LastEditTime : 2020-02-17 12:54:55
 * @Description: file content
 * @FilePath: \leetcode\1351.cpp
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define INF 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f

class ProductOfNumbers {
private:
    vector<int> _nums;
    vector<int> _products;
    vector<int> _pos_of_zero;
public:
    ProductOfNumbers() {
    }
    
    void add(int num) {
        if(num==0){
            _pos_of_zero.emplace_back(_nums.size());
        }
        int last=_products.empty()?1:_products.back();
        _products.emplace_back(last==0?num:last*num);
        _nums.emplace_back(num);
    }
    
    int getProduct(int k) {
        int pos=_nums.size()-k;
        if(_pos_of_zero.empty()){
            if(pos==0||_products[pos-1]==0){
                return _products.back();
            }else{
                return _products.back()/_products[pos-1];
            }
        }
        for(int i=0;i<_pos_of_zero.size();++i){
            if(_pos_of_zero[i]==pos||_pos_of_zero[i]>pos){
                return 0;
            }
        }
        if(pos==0||_products[pos-1]==0){
                return _products.back();
            }else{
                return _products.back()/_products[pos-1];
            }
        // auto low=lower_bound(_pos_of_zero.begin(),_pos_of_zero.end(),pos);
        // if(low==_pos_of_zero.end()||(*low)<pos){
        //     auto high=upper_bound(low,_pos_of_zero.end(),pos);
        //     if(high==_pos_of_zero.end()){
        //         return _products.back()/_products[pos-1];
        //     }else{
        //         return 0;
        //     }
        // }else{
        //     return 0;
        // }
    }
};

int main() {
    system("pause");
    return 0;
}