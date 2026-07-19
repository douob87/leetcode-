//找出s的最小右移字典序
string minimalString(const string& s){
        string t = s + s;
        int i = 0, j = 1, n = s.length();
        while(i<n && j<n){
            int k = 0;
            //t = "aaabaaaac"
            /*
            i=0 : a a a
            j=1 : a a b
            #以j開始的字典序大於以i開始的字典序。
            #同時，O a a < O a b，所以以j+1開始的也是，...，到從j+k開始的都排除。

            如果t[i+k] < t[j+k]
            i--------i+k
               j--------j+k
            這時候，以i開始的為答案，且j~j+k都排除，所以j移到***j+k+1***
            =======================================================================
            如果t[i+k] > t[j+k]
            這時候，以j開始的為答案，所以i需要移到j。而j需要移到max(j + 1, i + k + 1)
            i--------i+k 
                          j---------j+k  => i -> j, j -> j + 1
            
            i--------i+k
                j----------j+k => i -> j, j -> i + k + 1
            */
            while(k<n && t[i+k] == t[j+k])k++;
            if(t[i+k] < t[j+k]){
                j += k + 1;
            }else{
                int new_j = max(j, i + k) + 1;
                i = j;
                j = new_j;
            }
        }
        return t.substr(i, n);
    }