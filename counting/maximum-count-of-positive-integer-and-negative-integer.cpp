class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pcount = 0, ncount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0)
                ncount++;
            if (nums[i] > 0)
                pcount++;
        }
        return max(pcount, ncount);
    }
};