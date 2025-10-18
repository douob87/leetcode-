//vector<int> nums; 
//int n = nums.size();

//前綴和
vector<int> pref(n+1, 0);
for(int i=0;i<n;i++)pref[i+1] = pref[i] + nums[i];//[l, r] = pref[r+1] - pref[l];

//後綴和
vector<int> suff(n+1, 0);
for(int i=0;i<n;i++)suff[i] = suff[i+1] + nums[i];//suff[i] = [i ~ n-1]