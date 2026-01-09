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