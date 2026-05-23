class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int>mp1;
        for(char x:s) mp1[x]++;
        unordered_map<char,int>mp2;
        for(char y:t) mp2[y]++;
        return mp1==mp2;
    }
};