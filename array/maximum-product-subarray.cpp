class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxp=nums[0]; int minp=nums[0];
        int res=nums[0];
        for(int i = 1; i<n; i++){
            if(nums[i]<0) swap(minp,maxp);
            maxp=max(nums[i],maxp*nums[i]);
            minp=min(nums[i],minp*nums[i]);
            res=max(res,maxp);
        }
        return res;
    }
};