//小於等於 N(上界)
//https://leetcode.com/problems/numbers-at-most-n-given-digit-set/description/
string s = to_string(n);
int m = s.length();
int dp[10];
memset(dp, -1, sizeof(dp));
auto dfs = [&](this auto&& dfs, int i, bool isHigh, bool isNum){
    if(i == m)return isNum;
    //前面被限制過，沒必要被記憶。
    if(!isHigh && isNum && dp[i]!=-1)return dp[i];
    int res = 0;
    //前面跳過。
    if(!isNum)res = dfs(i+1, false, false);
    
    int hi = (isHigh) ? s[i]-'0' : 9;
    int d0 = (isNum) ? 0 : 1;

    for(int j=0;j<digits.size();j++){
        int x = stoi(digits[j]);
        if(d0<=x && x<=hi){
            res += dfs(i+1, isHigh&&(x==hi), true);
        }
    }
    if(!isHigh && isNum)return dp[i] = res;
    return res;
};
dfs(0, true, false);

//限制上下界(LOW ~ HIGH)
//https://leetcode.com/problems/number-of-beautiful-integers-in-the-range/submissions/1831064639/
 string l = to_string(low), h = to_string(high);
int n = l.length(), m = h.length(), diff = m-n;
l = string(diff, '0') + l;
int dp[10][20][21];
memset(dp, -1, sizeof(dp));
auto dfs = [&](this auto&& dfs, int i, int cnt, int mod, bool isLow, bool isHigh, bool isNum){
    if(i == m)return (cnt==m && mod==0 && isNum) ? 1 : 0;
    if(!isLow && !isHigh && isNum && dp[i][cnt][mod]!=-1)return dp[i][cnt][mod];
    int res = 0;
    //如果跳過，isLow要限制，eg. 23 ~ 100，如果第一位跳過了，接下來至少要從2 ~ 9。
    if(!isNum && l[i]=='0')res = dfs(i+1, cnt, mod, true, false, false);/***isLow = true***/
    
    int lo = (isLow) ? l[i]-'0' : 0;
    int hi = (isHigh) ? h[i]-'0' : 9;
    int d0 = (isNum) ? 0 : 1;

    //d = max(d0, lo)
    for(int d=max(d0, lo) ; d<=hi ; d++){
        res += dfs(i+1, cnt+(d%2)*2-1, (mod*10+d)%k, isLow&&(d==lo), isHigh&&(d==hi), true);
    }

    if(!isLow && !isHigh && isNum)return dp[i][cnt][mod] = res;
    return res;
};
return dfs(0, m, 0, true, true, false);