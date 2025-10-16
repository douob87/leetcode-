//判斷graph(無向圖)是不是二分圖, 0(未塗色)，1(塗紅色)，2(塗藍色)
int n;//vertex個數
vector<vector<int>> graph;
vector<int> color(n, 0);
bool dfs(int x, int c){
    color[x] = c;
    for(const int& y : graph[x]){
        if(color[y]==c || color[y]==0&&!dfs(y, -c))return false;
    }
    return true;
}
for(int i=0;i<n;i++){
    if(color[i]==0 && !dfs(i, 1))return false;
}
return true;


