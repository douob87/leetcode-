//LeetCode 28. Find the Index of the First Occurrence in a String
int strStr(string text, string pattern) {
    int n = text.length(), m = pattern.length();
    vector<int> lcp(m, 0);
    //lcp[i] 代表 在位置i 能匹配多少長度的前綴
    //a b c a b a b
    //0 0 0 1 2 1 2

    //算法加速的關鍵 => j = lcp[j-1]
    //a b c d a b c z a b c k
    //0 0 0 0 1 2 3 0 1 2 3 0
    //              j       i
    //若 s[i], s[j]無法匹配，j不要直接從頭開始，可以掙扎一下。
    //如果j不為0，代表s[j-1]匹配成功，lcp[j-1]的位置，就是可以掙扎的點。思考上面的範例。
    for(int i=1,j=0;i<m;i++){
        char b = pattern[i];
        while(j && b!=pattern[j])j = lcp[j-1];
        if(b == pattern[j])j++;
        lcp[i] = j;
    }

    for(int i=0,j=0;i<n;i++){
        char b = text[i];
        while(j && b!=pattern[j])j = lcp[j-1];
        if(b == pattern[j])j++;
        if(j == m)return i-m+1;
    }
    return -1;
}