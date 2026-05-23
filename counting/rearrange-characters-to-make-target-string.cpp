class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char ,int>c1,c2;
        for(char ch: s){
            c1[ch]++;
        }
        for(char ch:target){
            c2[ch]++;
        }
        int ans= INT_MAX;
        for(int i=0;i<target.size();i++){
            ans=min(ans,c1[target[i]]/c2[target[i]]);
        }
        return ans;
    }

};