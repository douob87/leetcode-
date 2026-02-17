#include <bits/stdc++.h>
using namespace std;
class FenWick{
    vector<int> t;
public:
    FenWick(int n):t(n+1){}
    void update(int i, int add){
        while(i < t.size()){
            t[i] ^= add;
            i += i&-i;//加上 low bit
        }
    }
    //找 [1 ~ x] 的和 (1 - index)
    int pre(int i){
        int sum = 0;
        while(i > 0){
            sum ^= t[i];
            i -= i&-i;//減去 low bit
        }
        return sum;
    }
};
int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    int n = nums.size();
    FenWick t(n);
    for(int i=0;i<n;i++)t.update(i+1, nums[i]);
    cout<<t.pre(3)<<endl;
    cout<<t.query(2, 4)<<endl;
}
/*
t.update(i+1, 1); => 更新 nums[i]
t.pre(i+1); => 計算 nums[0 ~ i] 的和
t.query(l, r) => 計算 nums[l ~ r] 的和
*/