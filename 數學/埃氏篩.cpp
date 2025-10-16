int MX = 1'000'01;
vector<bool> sieve(MX, true);
sieve[0] = sieve[1] = false;

for(int i=2;i<MX;i++){
    if(!sieve[i])continue;
    for(long long j=1LL*i*i;j<MX;j+=i){//j 改 long long , 不然i*i可能爆掉
        sieve[j] = false;
    }
}

/*
sieve[x] = true => 質數
sieve[x] = false => 非質數
*/