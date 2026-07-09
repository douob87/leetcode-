class Solution {
public:
    string longestPalindrome(string s) {
        string new_s = "#";
        for(char& c : s){
            new_s.push_back(c);
            new_s.push_back('#');
        }
        int n = new_s.length(), center = 0, rad = 0;
        vector<int> radius(n, 0);
        for(int i=0;i<n;i++){
            int mirror = 2 * center - i;
            //如果new_s[mirror]的回文半徑沒有碰到左界，則radius[i]=radius[mirror]
            //如果超過左界，則為右界 - i
            if(i < rad){
                radius[i] = min(rad - i, radius[mirror]);
            }
            while(i-radius[i]-1>=0 && i+radius[i]+1<n && new_s[i-radius[i]-1]==new_s[i+radius[i]+1]){
                radius[i]++;
            }
            if(i+radius[i] > rad){
                rad = i + radius[i];
                center = i;
            }
        }
        string ans = "";
        for(int i=0;i<n;i++){
            int start_index = (i - radius[i]) / 2;
            if(radius[i] > ans.length()){
                ans = s.substr(start_index, radius[i]);
            }
        }
        return ans;
    }
};