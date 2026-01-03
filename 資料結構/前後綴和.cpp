//vector<int> nums; 
//int n = nums.size();

//前綴和
vector<int> pref(n+1, 0);
for(int i=0;i<n;i++)pref[i+1] = pref[i] + nums[i];//[l, r] = pref[r+1] - pref[l];

//後綴和
vector<int> suff(n+1, 0);
for(int i=0;i<n;i++)suff[i] = suff[i+1] + nums[i];//suff[i] = [i ~ n-1]

//二維前綴和
//pref[i][j] 代表 以 (0, 0), (i, j) 為對角線的長方形面積
/*
1 1 1    1 2 3
1 1 1 -> 2 4 6
1 1 1    3 6 9
*/
int m = grid.size(), n = grid[0].size();
vector<vector<int>> pref(m+1, vector<int>(n+1, 0));
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        pref[i+1][j+1] = pref[i][j+1] + pref[i+1][j] - pref[i][j] + grid[i][j];
    }
}
//計算 以左上角(a, b), 右下角(c, d) 為對角線的長方形面積
/*
#

     #
*/
pref[c+1][d+1] - pref[c+1][b] - pref[a][d+1] + pref[a][b];