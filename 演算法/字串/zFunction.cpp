//LeetCode 28. Find the Index of the First Occurrence in a String
int strStr(string text, string pattern) {
    int n = text.length(), m = pattern.length(), N = n+m, left = 0, right = 0;
    pattern.append(text);
    vector<int> z(N, 0);
    for(int i=1;i<N;i++){
        //z[i-left] 表示 s[i-left] 開始的 後綴 能匹配多少長度的 前綴。
        //right - i + 1 表示 s[i] 開始的後綴 "最多"能免費匹配 多少長度的 前綴。
        
        //s[0]
        // |  
        //[i   ...   R     ] => z[i-left]
        //[i   ...   R]      => right - i + 1
        if(i <= right)
            //以z[i - left] 為主，若 z[i - left] <= z[right-i+1] ，選 z[i - left]
            //                   若 z[i - left] > right-i+1 ，選 right-i+1
            //=> *選 min(z[i-left], right-i+1)
            z[i] = min(z[i-left], right-i+1);

        while(i+z[i]<N && pattern[z[i]]==pattern[i+z[i]]){
            left = i, right = i+z[i];
            z[i]++;
        }
        if(i>=m && z[i]>=m)return i-m;
    }
    return -1;
}