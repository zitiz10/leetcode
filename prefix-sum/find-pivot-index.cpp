class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalsum=0;
        for(int x : nums){
            totalsum+=x;
        }
        int lsum=0;
        for(int i=0;i<nums.size();i++){
            int rsum = totalsum - lsum - nums[i];
            if(rsum==lsum) return i;
            lsum+=nums[i];
        }
        return -1;
    }
};