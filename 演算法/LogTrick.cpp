/*
TC : O(31n)

OR : 如果"新的num" 加到 一個OR sum的集合 不會改變值，代表接下來的OR sum都會 "被包含"。所以 (nums[i]|nums[j]) == nums[j] 要 break
AND : 如果"新的num" 加到 一個AND sum的集合 不會改變值，代表接下來的AND sum都會 "包含"。所以 ......
GCD : 同理。
LCM : 同理。
*/
for(int i=0;i<n;i++){
    for(int j=i-1;j>=0;j--){
        if((nums[i] | nums[j]) == nums[j])break;
        nums[j] = nums[i] | nums[j];
    }
}

void LogTrick(vector<int>& nums){
    vector<pair<int, int>> or_left;
    for(int i=0;i<nums.size();i++){
        int x = nums[i];
        for(auto& [or_val, _] : or_left){
            or_val |= x;//添加 x 進去 ***自行修改***
        }
        or_left.push_back({x, i});

        //去重
        int m = 0;
        for(int j=1;j<or_left.size();j++){
            if(or_left[j].first != or_left[j-1].first){
                or_left[++m] = or_left[j];
            }
        }
        or_left.resize(m+1);

        for(int k=0;k<=m;k++){
            auto [or_val, left] = or_left[k];
            int right = (k<m-1) ? or_left[k+1].second - 1 : i;
            cout<<left<<" "<<right<<" "<<or_val<<endl;
        }
    }
}