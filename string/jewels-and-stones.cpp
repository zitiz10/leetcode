class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int>mp;
        for(char c:stones) mp[c]++;
    int jewelscount=0;
    for(char j:jewels){
        jewelscount+=mp[j];
    }
    return jewelscount;
}
};