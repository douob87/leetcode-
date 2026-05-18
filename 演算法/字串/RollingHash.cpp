/*
想法 : 把一段vector<> 或 string 壓成 一個數字 ， 放進HashTable後能 O(1) 的搜索
vec = [1, 2, 3, 4]
H = [1, 1 * BASE + 2, 1 * BASE^2 + 2 * BASE + 3, 1 * BASE^3 + 2 * BASE^2 + 3 * BASE + 4] => H[i] = H[i-1] * BASE + nums[i];
P = 階乘

get(l, r) => 如果要找 ([3, 4] = 3 * BASE + 4) => 
H[r] - H[l-1] * P[r-l+1] = 
(1 * BASE^3 + 2 * BASE^2 + 3 * BASE + 4) - (1 * BASE + 2) * (BASE^2) = (1 * BASE^3 + 2 * BASE^2 + 3 * BASE + 4) - (1 * BASE^3 + 2 * BASE^2) = 3 * BASE + 4
*/
using ull = unsigned long long;
//用隨機BASE可以避免hack, 構造不出不合理的答案。
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// static ull BASE = uniform_int_distribution<int>(131, 1e9)(rng);

//用static 因為不同object有使用同一份BASE
static ull BASE = 131;//13331
class RollingHash{
    vector<ull> H, P;
public:
    RollingHash(const vector<int>& nums){
        int n = nums.size();
        H.assign(n+1, 0);
        P.assign(n+1, 1);
        //calculate P
        for(int i=1;i<=n;i++)P[i] = P[i-1] * BASE;
        //calculte H
        //如果nums[i] < 0 要加offset => H[i+1] = H[i] * BASE + (ull)(nums[i] + offset);
        for(int i=0;i<n;i++)H[i+1] = H[i] * BASE + nums[i];
    }
    //閉區間
    ull get(int l, int r){
        return H[r+1] - H[l] * P[r-l+1];
    }
};