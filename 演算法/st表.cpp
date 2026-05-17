*** 1D ST表 ***
//bit_width(1u * n) = lg(n) + 1
//稀疏表 TC : O(n logn) || SC : O(n logn)
//查找區間[l, r]內的最大值、最小值等
//dp[i][j]代表 起始點i, 長度2^j 的區間，轉移方程st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1])
int n = nums.size(), wn = bit_width(1u * n);
vector<vector<int>> st(n, vector<int>(wn));

//*** 左閉右開 => [) ***
auto query = [&](int l, int r) -> int{
    int w = bit_width(r-l) - 1;
    return max(st[l][w], st[r-(1<<w)][w]);
};

for(int i=0;i<n;i++)st[i][0] = nums[i];

for(int k1=1; k1 < wn; k1++){
    for(int i=0; i < n - (1<<k1) + 1; i++){
        st[i][k1] = max(st[i][k1-1], st[i+(1<<(k1-1))][k1-1]);
    }
}
//cout<<query(l, r);

*** 2D ST表 ***
int m = matrix.size(), n = matrix[0].size();
int wm = bit_width(1u * m), wn = bit_width(1u * n);
//st[i][j][k1][k2] => (i, j) -> (i + (1<<k1)-1, j + (1<<k2)-1)
vector st(m, vector<array<array<int, 8>, 8>>(n));

for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        st[i][j][0][0] = matrix[i][j];
    }
}
/*i, j 邊界條件 
i + (1<<k1) - 1 < m => i < m - (1<<k1) + 1
j + (1<<k2) - 1 < n => j < n - (1<<k2) + 1
*/
//k1 = 0 先做列
for(int k2=1; k2<wn; k2++){
    for(int i=0; i<m; i++){
        for(int j=0; j < n - (1<<k2) + 1; j++){
            st[i][j][0][k2] = max(st[i][j][0][k2-1], st[i][j+(1<<(k2-1))][0][k2-1]);
        }
    }
}
//在各個寬度 的 行
for(int k1=1; k1<wm; k1++){
    for(int k2=0; k2<wn; k2++){
        for(int i=0; i < m - (1<<k1) + 1; i++){
            for(int j=0; j < n - (1<<k2) + 1; j++){
                st[i][j][k1][k2] = max(st[i][j][k1-1][k2], st[i+(1<<(k1-1))][j][k1-1][k2]);
            }
        }
    }
}
//左閉右開 => [)
auto query = [&](int x1, int y1, int x2, int y2) -> int{
    x1 = max(0, x1);
    y1 = max(0, y1);
    x2 = min(m, x2);
    y2 = min(n, y2);
    int w = bit_width(1u * (y2-y1)) - 1, h = bit_width(1u * (x2-x1)) - 1;
    return max({
        st[x1][y1][h][w],
        st[x1][y2-(1<<w)][h][w],
        st[x2-(1<<h)][y1][h][w],
        st[x2-(1<<h)][y2-(1<<w)][h][w]
    });
};