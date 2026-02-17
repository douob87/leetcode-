/*
         8
        / \
       5   7
      / \ / \
     1  2 3  4 
       / \   
      8   6
                                  2
上圖 最深節點的最近公共祖先(LCA) = /  \ 
                                8   6
思考點 : 若左子樹高度 == 右子樹高度 => LCA 為 {當前子樹}
             //      >     //    =>  LCA 為 {左子樹}
             //      <     //    =>  LCA 為 {右子樹}
*/
pair<TreeNode*, int> dfs(TreeNode* root){
    if(!root)return {nullptr, 0};
    auto [t1, d1] = dfs(root->left);
    auto [t2, d2] = dfs(root->right);
    if(d1 ==d2){//左子樹高度 == 右子樹高度
        return {root, d1+1};
    }else if(d1 > d2){//左子樹高度 > 右子樹高度
        return {left, d1+1};
    }else{//左子樹高度 < 右子樹高度
        return {right, d2+1};
    }
    //return {d1==d2 ? root : d1>d2 ? t1 : t2, max(d1, d2)+1};
}
/***********************************************************/
//倍增算法(Binary Lifting)
class TreeAncestor {
public:
    vector<vector<int>> fa;
    TreeAncestor(int n, vector<int>& parent) {
        int m = log2(n) + 1;
        fa.assign(n, vector<int>(m, -1));
        //base case
        for(int i=0;i<n;i++)fa[i][0] = parent[i];
        //fa[i][j] 表示 第 i 個node 往上 2^j 是誰？
        //fa[x][0] = parent[x]
        //fa[x][1] = fa[fa[x][0]][0]
        //轉移方程 : fa[x][i+1] = fa[fa[x][i]][i]
        for(int i=0;i<m-1;i++){
            for(int x=0;x<n;x++){
                int p = fa[x][i];
                if(p != -1){
                    fa[x][i+1] = fa[p][i];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(;k && node>=0;){
            node = pa[node][__builtin_ctz(k)];
            k &= (k-1);
        }
        return node;
    }
};
//lca + 樹上時間戳 + kth_ancestor
class LcaBinaryLifting{
    vector<int> depth;
    vector<vector<int>> pa;
public:
    vector<int> in, out;
    LcaBinaryLifting(vector<vector<int>>& edges){
        int n = edges.size() + 1//自行調整成 node 個數
        int m = __lg(n) + 1;
        vector<vector<int>> g(n);
        for(auto& e : edges){
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int time = 0;//全局時間戳
        depth.resize(n);//node 深度
        in.resize(n);
        out.resize(n);
        pa.resize(n, vector<int>(m, -1));

        auto dfs = [&](this auto&& dfs, int x, int fa)->void{
            pa[x][0] = fa;
            in[x] = ++time;
            for(int y : g[x]){
                if(y != fa){
                    depth[y] = depth[x] + 1;
                    dfs(y, x);
                }
            }
            out[x] = time;
        };
        dfs(0, -1);

        //x 往上 4 個 = x 往上 2 個 再 往上 2 個。
        //pa[x][2] = pa[pa[x][1]][1] = pa[x][i+1] = pa[pa[x][i]][i];
        for(int i=0;i<m-1;i++){
            for(int x=0;x<n;x++){
                int p = pa[x][i];
                if(p != -1){
                    pa[x][i+1] = pa[p][i];
                }
            }
        }
    }
    int kth_ancestor(int node, int k){
        //往上k=13(1101)個node -> 往上2^0 + 2^2 + 2^3
        //__builtin_ctz()後綴零、__builtin_clz()前綴零、__builtin_popcount() 1's數量。
        while(node>=0 && k){
            node = pa[node][__builtin_ctz(k)];
            k &= (k-1);
        }
        return node;
    }
    int lca(int x, int y){
        if(depth[x] > depth[y])swap(x, y);//讓node[x]的depth 小，node[y]的depth 大
        y = kth_ancestor(y, depth[y] - depth[x]);//讓node[y]上升到node[x]的高度
        if(x == y)return x;
        for(int i=pa[0].size()-1;i>=0;i--){
            int px = pa[x][i], py = pa[y][i];
            if(px != py){
                x = px;
                y = py;
            }
        }
        return pa[x][0];
    }
};