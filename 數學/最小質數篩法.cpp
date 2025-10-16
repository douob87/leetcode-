int MX = 1'000'01;
vector<int> spf(MX, 0);
iota(spf.begin(), spf.end(), 0);//把 spf[i] 設為自己

for(int i=2;i<MX;i++){
    if(spf[i] != i)continue;//已經被標記
    for(long long j=1LL*i*i;j<MX;j+=i){
        if(spf[j] == j){//還沒被標記 就修改
            spf[j] = i;
        }
    }
}

//質因數分解 => 20 = 2 * 2 * 5
int x = 2486;
unordered_map<int, int> factor;
while(x != 1){
    factor[spf[x]] ++;
    x /= spf[x];
}