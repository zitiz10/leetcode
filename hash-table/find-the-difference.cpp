class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mp1;
        for(char c:s) mp1[c]++;
        unordered_map<char,int>mp2;
        for(char x:t) mp2[x]++;
        for(auto x: mp2){
            if(mp1[x.first]!=x.second) return x.first;
        }
       return -1;
    }
};