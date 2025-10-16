class SegmentTree{
    int n;
    vector<int> mx;
public:
    SegmentTree(const vector<int>& nums){
        n = nums.size();
        mx.resize(4*n);
        build(nums, 1, 0, n-1);
    }
    int merge_val(int a, int b){
        return max(a, b);
    }
    void maintain(int o){
        merge_val(t[o*2], t[o*2+1]);
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
            query(o*2+1, m+1, r, ql, qr);
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
};
/*
vector<int> nums;
int n = nums.size();
SegmentTree t(nums);
t.query(1, 0, n-1, l, r);求區間[l, r] 的 最大值(or 和、最小值等)
t.update(1, 0, n-1, i, val);把 nums[i] 更新成 val
*/