class UnionFind{
    vector<int> parent;
public:
    vector<int> conn;
    int cc;   
    UnionFind(int n){
        conn.assign(n, 0)
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
};
/*
UnionFind uf(n);
uf.cc; => 連通塊個數
uf.Union(u, v); => merge 兩個連通塊
uf.Find(node); => 找到node的祖先節點
uf.conn[Find(node)]; => node的連通塊個數
*/