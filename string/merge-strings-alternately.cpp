class Solution {
private: 
string ans;
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        while(i<word1.length() || i<word2.length()){
            if(i<word1.length()){
                ans+=word1[i];
            }
            if(i<word2.length()){
                ans+=word2[i];
            }
            i++;
        }
        return ans;
    }
};