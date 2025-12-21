int t = 0//全局時間戳
int in[n], out[x];

function<void(int, int)> dfs = [&](int x, int fa){
    in[x] = ++t;
    for(int y : g[x]){
        if(y != fa){
            dfs(y, x);
        }
    }
    out[x] = t;
};
dfs(0, -1);

//判斷 x 是否為 y 的父節點
//1.in[x] <= in[y]; 父節點的進入時間 一定小於等於 子節點進入時間
//2.out[y] <= out[x]; 子節點離開時間 一定小於等於 父節點離開時間
//3.in[y] <= out[y]; 節點進入時間 一定小於等於 離開時間
//結論 => in[x] <= in[y] <= out[x]
function<bool(int, int)> isParent = [&](int x, int y)->bool{
    return in[x] <= in[y] && in[y] <= out[x];
};

//dfs() 的先後代表意義

//先遞迴 (後序 bottom - up)
//先求 子節點 相關的資訊
for(int y : g[x]){
    if(y != fa){
        dfs(y, x);
        //do something
    }
}

//後遞迴 (前序 top - down)
//把 父節點 的資訊往下傳
for(int y : g[x]){
    if(y != fa){
        //do something
        dfs(y, x);
    }
}