#include <bits/stdc++.h>
using namespace std;
/*
int MX = 1'000'01;
vector<int> spf(MX, 0);
iota(spf.begin(), spf.end(), 0);
for(int i=2;i<MX;i++){
    //已經被標記
    if(spf[i] != i)continue;
    for(long long j=1LL*i*i;j<MX;j+=i){
        //還沒被標記 就修改
        if(spf[j] == j){
            spf[j] = i;
        }
    }
}
*/
int main(){
    int MX = 1'000'01;
    vector<int> spf(MX, 0);
    for(int i=2;i<MX;i++){
        //已經被標記
        if(spf[i] != 0)continue;
        for(long long j=i;j<MX;j+=i){
            //還沒被標記 就修改
            if(spf[j] == 0){
                spf[j] = i;
            }
        }
    }
   //質因數分解 => 20 = 2 * 2 * 5
    int x = 2486;
    while(x != 1){
        cout<<spf[x]<<endl;
        x /= spf[x];
    } 
}
