class UnionFind{
    vector<int> parent;
public:
    vector<int> conn;
    int cc;   
    UnionFind(int n){
        conn.assign(n, 1);
        parent.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
        cc = n;
    }
    void Union(int x, int y){
        x = Find(x);
        y = Find(y);
        if(x != y){
            parent[x] = y;
            conn[y] += conn[x];
            cc --;
        }
    }
    int Find(int x){
        return parent[x]==x ? x : parent[x]=Find(parent[x]);
    }
    void Reset(int x){
        parent[x] = x;
    }
    bool Connected(int x, int y){
        return Find(x) == Find(y);
    }
};
/*
UnionFind uf(n);
uf.cc; => 連通塊個數
uf.Union(u, v); => merge 兩個連通塊
uf.Find(node); => 找到node的祖先節點
uf.Reset(node); => 刪除邊
uf.Connected(u, v); => 確認u, v是否在同一個連通塊
uf.conn[Find(node)]; => node的連通塊個數
*/

//帶權並查集
class UnionFind{
    vector<int> pa, dis;
public:
    UnionFind(int n) : pa(n), dis(n){
        ranges::iota(pa, 0);
    }
    bool Union(int from, int to, int val){
        int x = Find(x);
        int y = Find(y);
        /*
                    x
                    |
                    |
                   / \
                  /   \
                from  to
        */
        //from -> to = (from->x) - (to->x) = dis[from] - dis[to]
        //dis代表相對距離，可能小於0。
        if(x == y)return (dis[from] - dis[to]) == val;
        /*
             x           y
            /           /
           /           /
         from---------to
        */
        // to->y + from->to = x->y + from->x, so x->y = (from->to) + (to->y) - (from->x); 
        //x -> y = 
        dis[x] = val + dis[to] - dis[from];
        return true;
    }
    //遞歸，若在 recursion 前執行動作，則代表在"遞"的時候處理。反之，則代表在"歸"。
    int Find(int x){
        if(pa[x] != x){
            int root = Find(pa[x]);
            dis[x] += dis[pa[x]];
            pa[x] = root;
        }
        return pa[x];
    }
};