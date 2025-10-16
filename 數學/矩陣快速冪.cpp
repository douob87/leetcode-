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