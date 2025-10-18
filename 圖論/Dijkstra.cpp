//適用 邊權值>=0 
//TC : O(|V+E| logE)
using T = array<int, 3>;
int n = mat.size(), m = mat[0].size();
vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
vector<int> dir = {1, 0, -1, 0, 1};
queue<T> q;
q.push({0, 0, 0});
dist[0][0] = 0;

while(!q.empty()){
    auto [step, i, j] = q.front();q.pop();
    if(step > dist[i][j])continue;//當前走過更少步 沒必要再走
    if(i==n-1 && j==m-1)return step; 

    for(int d=0;d<4;d++){
        int ni = i + dir[d];
        int nj = j + dir[d+1];
        if(ni>=0 && nj>=0 && ni<n && nj<m){
            int new_step = step + path[ni][nj];
            if(new_step < dist[ni][nj])
                q.push({new_step, ni, nj});
        }
    }
}
return -1;