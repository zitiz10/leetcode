class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        int n=nums.size();
        for(int x:nums) map[x]++;
        vector<vector<int>>bucket(n+1);
        for(auto it:map){
            bucket[it.second].push_back(it.first);
        }
        vector<int>res;

        for(int i=bucket.size()-1;i>=0;i--){
            for(int x:bucket[i]){
                res.push_back(x);
                if(res.size()==k) return res;
            }
        }
        return res;
    }
};