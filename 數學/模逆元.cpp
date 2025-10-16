//(a/b) % p => 轉換成 a * b^-1(a 乘上 b的逆元)
//b = qpow(b, MOD-2) % MOD, 費馬小定理
int MOD = 1'000'000'007;//1e9 + 7
int MX = 41;
int F[MX];
int INV_F[MX];

long long qpow(int a, int n){
    long long res = 1;
    while(n){
        if(n & 1){
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res;
}

F[0] = 1;
for(int i=1;i<MX;i++)F[i] = i * F[i-1] % MOD;
INV_F[MX-1] = qpow(F[MX-1], MOD-2);
for(int i=MX-1;i;i--)INV_F[i-1] = INV_F[i] * i % MOD;//計算模逆元，1 / (1*2) = 1 / (1*2*3) * 3

/*
C(n, m) = n! / (m)! / (n-m)!
計算C(n, m) % MOD = F[n] * INV_F[m] % MOD * INV_F[n-m] % MOD;
*/