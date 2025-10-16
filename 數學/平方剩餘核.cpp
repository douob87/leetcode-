//把一個數 質因數分解，次方數是偶數=>次方變0 ; 次方數是奇數=>次方變1
//72 = 2^3 * 3^2 => 2
int MX = 1'000'01;
vector<int> core(MX, 0);

for(int i=2;i<MX;i++){
    if(core[i] != 0)continue;//已經被標記
    for(long long j=1;i*j*j<MX;j+=i){
        core[i*j*j] = i;
    }
}