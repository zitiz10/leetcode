class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int ans = 0;
        for (int x : set) {
            if (set.find(x - 1) == set.end()) {
                int current = x;
                int length = 1;

                while (set.find(current + 1) != set.end()) {
                    current++;
                    length++;
                }
                ans = max(ans, length);
            }
        }
        return ans;
    }
};