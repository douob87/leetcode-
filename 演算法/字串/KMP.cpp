//LeetCode 28. Find the Index of the First Occurrence in a String
int strStr(string text, string pattern) {
    int n = text.length(), m = pattern.length();
    vector<int> lcp(m, 0);
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