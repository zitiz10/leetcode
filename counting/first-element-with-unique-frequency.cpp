class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m1,m2;

        for(int i:nums) m1[i]++;
        for(auto i:m1) m2[i.second]++;
        for(int i=0;i<n;i++){
            if(m2[m1[nums[i]]]==1)
            return nums[i];
        }
        return -1;
    }
};