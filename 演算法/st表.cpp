//稀疏表 TC : O(n logn) || SC : O(n logn)
//查找區間[l, r]內的最大值、最小值等
//dp[i][j]代表 起始點i, 長度2^j 的區間，轉移方程st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1])
int n = 101;
vector<int> nums(n);
vector<vector<int>> st(MX, vector<int>(ceil(log2(MX))+1, 0));
int query(int l, int r){
    int j = log2(r-l+1);
    return max(st[l][j], st[r-(1<<j)+1][j]);
}
//base case
for(int i=0;i<n;i++)st[i][0] = nums[i];
//dp
for(int j=1 ; j<=log2(n) ; j++){
    for(int i=0 ; i+(1<<(j-1))<n ; i++){
        st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
    }
}

//cout<<query(l, r);