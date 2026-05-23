class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int mind = n;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                int curr = abs(i - start);
                mind = min(mind, curr);
            }
        }
        return mind;
    }
};