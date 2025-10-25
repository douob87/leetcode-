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