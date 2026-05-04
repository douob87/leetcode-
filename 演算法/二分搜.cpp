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

//leetcode 二分 開區間模板
int left = -1, right = n;//(-1, n) 
auto check = [&](int x){
    //pass
};
while(left+1 < right){
    int mid = left + (right - left) / 2;
    (check(mid) ? right : left) = mid; //(最大值 最小化) FFFFFTTTTT
  //(check(mid) ? left : right) = mid; //(最小值 最大化) TTTTTFFFFF
}
return right;
//return left;

//庫函數 左閉右開
lower_bound(nums.begin(), nums.end(), target);//找第一個 >= target, 減 1 變成 找最後一個 < target的number
upper_bound(nums.begin(), nums.end(), target);//找第一個 > target, 減 1 變成 找最後一個 <= target的number

//對 vector<vector<int>> 中的第 ? 個 二分 
//eg. x = {{0, 0}, {1, 1}} //對x[i] 的第 ? 個值 二分。 
lower_bound(nums.begin(), nums.end(), target, [](auto& e, int val){
    return e[?] < val;
});
while(left < right){
    int i = left + (right - left)/2;
    if(e[i] < val){
        left = i + 1;
    }else{
        right = i;
    }
    return left;
}

upper_bound(nums.begin(), nums.end(), target, [](int val, auto& e){
    return e[i] > val;
});
while(left < right){
    int i = left + (right - left)/2;
    if(e[i] > val){
        right = i;
    }else{
        left = i + 1;
    }
    return right;
}