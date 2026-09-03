class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int odd = INT_MAX;
        for (int num : nums) {
            if (num % 2 == 1) {
                odd = min(odd, num);
            }
        }
        if (odd == INT_MAX)
            return true;
        for (int num : nums) {
            if (num % 2 == 0 && num <= odd)
                return false;
        }
        return true;
    }
};