//全源最短路徑
//枚舉中繼點 TC : O(n^3) || SC : O(n^2)
//想法 i->j = i->k->j
//轉移方程 => dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
    }
}
