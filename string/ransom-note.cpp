class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<char,int>map;
        for(char c:m)
         map[c]++;
        for(char c:r) {
            if(map[c]==0) return false;
            map[c]--;
        }
        return true;
    }
};