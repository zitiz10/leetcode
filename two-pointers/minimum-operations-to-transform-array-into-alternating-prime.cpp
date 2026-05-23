class Solution {
public:
    bool isprime(int n) {
        if (n < 2)
            return false;
        for (int i = 2; i<=sqrt(n); i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int mino = 0;
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            if (i % 2 == 0) {
                while (!isprime(val)) {
                    val++;
                    mino++;
                }
            } else {
                while (isprime(val)) {
                    val++;
                    mino++;
                }
            }
        }
        return mino;
    }
};