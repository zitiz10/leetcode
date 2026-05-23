class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int,int>mp;
        for(int x: bulbs){
            mp[x]++;
        }
        vector<int>ans;
        for(auto i: mp){
            if(i.second % 2 !=0)
                ans.push_back(i.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};