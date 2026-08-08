class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() <= 1)
            return false;
        sort(nums.begin(), nums.end());
        int i = 0, j = 1;
        while(j< nums.size()){
        if (nums[i] == nums[j])
            return true;
        else
            i++, j++;
        }
        return false;
    }
};