class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i = 0; i < 10; i++) {
            int temp = n + i;
            int pro = 1;
            while (temp) {
                int r = temp % 10;
                pro *= r;
                temp /= 10;
            }
            if (pro % t == 0)
                return n + i;
        }
        return -1;
    }
};