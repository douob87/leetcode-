#include <bits/stdc++.h>
using namespace std;
const int MX = 5000, BASE = 10;
vector<int> pal;
void generate_pal(){
    pal = {0};//Dummy node
    for(int p=1; ;p*=BASE){
        //生成奇數回文
        for(int i=p;i<p*BASE;i++){
            int x = i;
            for(int t=i/BASE;t;t/=BASE){
                x = x*BASE + t%BASE;
            }
            if(x > MX){
                pal.push_back(5005);
                return ;
            }
            pal.push_back(x);
        }
        //生成偶數回文
        for(int i=p;i<p*BASE;i++){
            int x = i;
            for(int t=i;t;t/=BASE){
                x = x*BASE + t%BASE;
            }
            if(x > MX){
                pal.push_back(5005);
                return ;
            }
            pal.push_back(x);
        }
    }
}
int main(){
    generate_pal();
    //for(int p : pal)cout<<p<<" ";
    /*
    要找最近的回文數的話, 11, 22, 33, 44, 55, >= 31的value在22 33之間。
    int j = lower_bound(pal.begin(), pal.end(), x) - pal.begin();
    x 一定在 pal[j-1] ~ pal[j] 之間 
    */
}