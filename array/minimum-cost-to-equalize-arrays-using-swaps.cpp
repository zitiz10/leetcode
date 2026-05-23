class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        for(int x: nums1) m[x]++;
        for(int x: nums2) m[x]--;
        int ans=0;
        for(auto[k,v] : m){
            if(v%2!=0) return -1;
            if(v>0) ans+=v/2; 
        }
        return ans;
    }
};