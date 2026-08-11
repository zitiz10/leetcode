class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> set;
        for (int x : nums) {
            set.insert(x);
        }
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else
                break;
        }
        while (set.count(sum)) {
            sum++;
        }
        return sum;
    }
};