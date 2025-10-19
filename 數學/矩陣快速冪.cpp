//計算 a ^ n , O(logn)
int qpow(int a, int n){
    int res = 1;
    while(n){
        if(n & 1){
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
}

//矩陣版
const int N = 2;
int MOD;
using Matrix = array<array<long long, N>, N>;
Matrix mul(Matrix& a, Matrix& b){
    Matrix c{};
    for(int i=0;i<N;i++){
        for(int k=0;k<N;k++){
            if(a[i][k] == 0)continue;
            for(int j=0;j<N;j++){
                c[i][j] = (c[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
            }
        }
    }
    return c;
}
Matrix qpow(Matrix& a, int n){
    Matrix res{};
    for(int i=0;i<N;i++)res[i][i] = 1;
    while(n){
        if(n & 1){
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}