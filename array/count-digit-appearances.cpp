class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            while (temp != 0) {
                int d = temp % 10;
                if (d == digit)
                    count++;
                temp /= 10;
            }
        }
        return count;
    }
};