#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums = {1, 5, 1, 4, 5, 1, 3};
    int n = nums.size();

    vector<int> left(n);//左邊最近 且 嚴格大於
    vector<int> stk = {-1};//存下標
    for(int i=0;i<n;i++){
        int x = nums[i];
        while(stk.size()>1 && nums[stk.back()] <= x)stk.pop_back();
        left[i] = stk.back();
        stk.push_back(i);
    }

    vector<int> right(n);
    stk = {n};
    for(int i=n-1;i>=0;i--){
        int x = nums[i];
        while(stk.size()>1 && nums[stk.back()] <= x)stk.pop_back();
        right[i] = stk.back();
        stk.push_back(i);
    }

    //cout
    for(int& x : left)cout<<x<<" ";
    cout<<endl;
    for(int& x : right)cout<<x<<" ";
}