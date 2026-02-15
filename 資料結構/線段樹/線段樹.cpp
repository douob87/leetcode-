#include <bits/stdc++.h>
using namespace std;
class SegmentTree{
    int n;
    vector<int> mx;
    int merge_val(int a, int b){
        return max(a, b);
    }
    void maintain(int o){
        mx[o] = merge_val(mx[o*2], mx[o*2+1]);
    }
    void build(const vector<int>& nums, int o, int l, int r){
        if(l == r){
            mx[o] = nums[l];
            return ;
        }
        int m = l + (r - l) / 2;
        build(nums, o*2, l, m);
        build(nums, o*2+1, m+1, r);
        maintain(o);
    }
    int query(int o, int l, int r, int ql, int qr){
        if(ql<=l && r<=qr){
            return mx[o];
        }
        int m = l + (r - l) / 2;
        if(m >= qr)
            return query(o*2, l, m, ql, qr);
        if(m < ql)
            return query(o*2+1, m+1, r, ql, qr);

        return merge_val(
            query(o*2, l, m, ql, qr),
            query(o*2+1, m+1, r, ql, qr)
        );
    }
    void update(int o, int l, int r, int i, int val){
        if(l == r){
            mx[o] = val;
            return ;
        }
        int m = l + (r - l) / 2;
        if(m >= i)
            update(o*2, l, m, i, val);
        else
            update(o*2+1, m+1, r, i, val);
        maintain(o);
    }
    int findFirst(int o, int l, int r, int val){
        if(mx[o] < val)return -1;
        if(l == r)return l;

        int m = l + (r - l) / 2;
        int i = findFirst(o*2, l, m, val);
        if(i < 0)
            i = findFirst(o*2+1, m+1, r, val);
        return i;
    }
public:
    SegmentTree(const vector<int>& nums){
        n = nums.size();
        mx.resize(4*n);
        build(nums, 1, 0, n-1);
    }
    void update(int i, int val){
        update(1, 0, n-1, i, val);
    }
    int query(int l, int r){
        return query(1, 0, n-1, l, r);
    }
    int findFirst(int val){
        return findFirst(1, 0, n-1, val);
    }
};
int main(){
    vector<int> nums = {1, 2, 4, 3, 5};
    int n = nums.size();
    SegmentTree t(nums);

    t.update(2, 10);
    cout<<t.query(0, n-1)<<endl;
    cout<<t.findFirst(5)<<endl;
}
/*
t.query(l, r);求區間[l, r] 的 最大值(or 和、最小值等)
t.update(i, val);把 nums[i] 更新成 val
t.findFirst(val);找第一個值 >= 為val 的 index
*/