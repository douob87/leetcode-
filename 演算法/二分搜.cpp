//二分搜搜索 三種寫法 找第一個 ( >= x ) 的 index
vector<int> nums;
sort(nums.begin(), nums.end());
int n = nums.size();
//假設 x 是 3
//閉區間
/*
    l
1 2 3 4 5
  r
*/
int left = 0, right = n-1;
while(left <= right){
    int mid = left + (right - left) / 2;//同 int mid = (left + right) / 2; 但可能overflow
    if(nums[mid] < x){
        left = mid + 1;
    }else{
        right = mid - 1;
    }
}
return left;
//半開區間(左閉右開)
/*
    l
1 2 3 4 5
    r
*/
int left = 0, right = n;
while(left < right){
    int mid = left + (right - left) / 2;//同 int mid = (left + right) / 2; 但可能overflow
    if(nums[mid] < x){
        left = mid + 1;
    }else{
        right = mid;
    }
}
return left;//or return right;
//開區間
/*
  l
1 2 3 4 5
    r
*/
int left = -1, right = n;
while(left + 1 < right){
    int mid = left + (right - left) / 2;//同 int mid = (left + right) / 2; 但可能overflow
    if(nums[mid] < x){
        left = mid;
    }else{
        right = mid;
    }
}
return right;