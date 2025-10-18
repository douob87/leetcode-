#include <bits/stdc++.h>
using namespace std;
class SegmentTree{
    int n;
    vector<int> todo;
    vector<int> t;
    int merge_val(int a, int b){
        return a + b;
    }
    void maintain(int o){
        t[o] = merge_val(t[o*2], t[o*2+1]);
    }
    void build(const vector<int>& nums, int o, int l, int r){
        if(l == r){
            t[o] = nums[l];
            return ;
        }
        int m = l + (r - l) / 2;
        build(nums, o*2, l, m);
        build(nums, o*2+1, m+1, r);
        maintain(o);
    }
    void do_(int o, int l, int r, int val){
        t[o] += (r-l+1) * val;
        todo[o] = val;
    }
    int query(int o, int l, int r, int ql, int qr){
        if(ql<=l && r<=qr){
            return t[o];
        }
        int m = l + (r - l) / 2;
        if(todo[o]){
            do_(o*2, l, m, todo[o]);
            do_(o*2+1, m+1, r, todo[o]);
            todo[o] = 0;
        }
        if(m >= qr)
            return query(o*2, l, m, ql, qr);
        if(m < ql)
            return query(o*2+1, m+1, r, ql, qr);

        return merge_val(
            query(o*2, l, m, ql, qr),
            query(o*2+1, m+1, r, ql, qr)
        );
    }
    void update(int o, int l, int r, int ql, int qr, int val){
        if(ql<=l && r<=qr){
            do_(o, l, r, val);
            return ;
        }
        int m = l + (r - l) / 2;
        if(todo[o]){
            do_(o*2, l, m, todo[o]);
            do_(o*2+1, m+1, r, todo[o]);
            todo[o] = 0;
        }
        if(m >= ql)
            update(o*2, l, m, ql, qr, val);
        if(m < qr)
            update(o*2+1, m+1, r, ql, qr, val);
        maintain(o);
    }
public:
    SegmentTree(const vector<int>& nums){
        n = nums.size();
        t.assign(4*n, 0);
        todo.assign(4*n, 0);
        build(nums, 1, 0, n-1);
    }
    void update(int l, int r, int val){
        return update(1, 0, n-1, l, r, val);
    }
    int query(int l, int r){
        return query(1, 0, n-1, l, r);
    }
};

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    int n = nums.size();
    SegmentTree t(nums);
    t.update(0, 2, 3);
    cout<<t.query(0, n-1);
}
/*
t.update(l, r, val); 把[l, r] 增加 val
t.query(l, r); 求區間[l, r] 的 sum
*/