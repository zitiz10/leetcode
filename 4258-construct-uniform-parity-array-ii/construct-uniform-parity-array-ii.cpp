class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int mn = nums[0], oddcnt = 0;
        for (int n : nums) {
            mn = min(mn, n);
            if (n % 2 == 1)
                oddcnt++;
        }
        return mn % 2 || oddcnt == 0;
    }
};