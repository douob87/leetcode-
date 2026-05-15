class xorBasic{
public:
    vector<int> b;
    xorBasic(int n):b(n){}

    void insert(int x){
        for(int i=b.size()-1;x && i>=0;i--){
            if((x>>i) & 1){
                if(b[i] == 0){
                    b[i] = x;
                    return ;
                }
                x ^= b[i];
            }
        }
    }

    int max_xor(){
        int res = 0;
        for(int i=b.size()-1;i>=0;i--){
            if((res ^ b[i]) > res)
                res ^= b[i];
        }
        return res;
    }
};