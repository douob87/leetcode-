//從(0,0) 走到 (n-1, m-1) 走幾步; 0代表路， 1代表牆
using T = array<int, 3>;
int n = mat.size(), m = mat[0].size();
vector<int> dir = {1, 0, -1, 0, 1};
queue<T> q;
q.push({0, 0, 0});

while(!q.empty()){
    auto [step, i, j] = q.front();q.pop();
    if(mat[i][j]==1)continue;
    mat[i][j] = 1;
    if(i==n-1 && j==m-1)return step; 
    for(int d=0;d<4;d++){
        int ni = i + dir[d];
        int nj = j + dir[d+1];
        if(ni>=0 && nj>=0 && ni<n && nj<m && !mat[ni][nj]){
            q.push({step+1, ni, nj});
        }
    }
}
return -1;