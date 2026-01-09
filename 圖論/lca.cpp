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
        int m = log2(k) + 1;
        for(int i=0;i<m;i++){
            if(k>>i & 1){
                node = fa[node][i];
            }
            if(node < 0)break;
        }
        return node;
    }
};