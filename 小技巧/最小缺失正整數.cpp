在一個包含 正整數 的arr找出第k個缺失正整數。
eg. [1, 2, 4], k=2 => missing = [3, 5, ...] => return 5
//推導
對於arr[i]之前(包含)共有 arr[i] - (i+1) 個缺失正整數。
eg. a = [1, 3, 4, 5, 6], 對於 a[3] = 5 之前共有 a[3] - (3+1) = 5-4 = 1個缺失正整數。
                               
二分出arr[i]之前的缺失正整數個數 >= k 的下標 i => <k | >=k
arr[i] - 1 是第 arr[i]-1-i個缺失正整數，題目需要找到第k個，所以 arr[i]-1 要往前找 arr[i]-1-i-k個數字
也就是 arr[i]-1 - (arr[i] - 1 - i - k) = i + k 即為答案。

1539. Kth Missing Positive Number
https://leetcode.com/problems/kth-missing-positive-number/description/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = -1, right = arr.size();
        while(left+1 < right){
            int mid = left + (right - left) / 2;
            (arr[mid]-mid-1>=k ? right : left) = mid;
        }
        return right + k;
    }
};