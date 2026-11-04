
class Solution {
public:

    struct SlidingMedian {

        multiset<int> left, right;
        long long sumLeft = 0, sumRight = 0;
        int target;

        SlidingMedian(int x) {
            target = x / 2 + 1;
        }

        void rebalance() {

            while(left.size() > target) {

                auto it = prev(left.end());
                int val = *it;

                left.erase(it);
                sumLeft -= val;

                right.insert(val);
                sumRight += val;
            }

            while(left.size() < target) {

                auto it = right.begin();
                int val = *it;

                right.erase(it);
                sumRight -= val;

                left.insert(val);
                sumLeft += val;
            }
        }

        // Insert without rebalancing
        void add(int val) {

            if(left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                sumLeft += val;
            }
            else {
                right.insert(val);
                sumRight += val;
            }
        }

        // Remove without rebalancing
        void remove(int val) {

            auto it = left.find(val);

            if(it != left.end()) {
                left.erase(it);
                sumLeft -= val;
            }
            else {
                it = right.find(val);
                right.erase(it);
                sumRight -= val;
            }
        }

        long long getCost() {

            long long median = *left.rbegin();

            return median * (long long)left.size() - sumLeft
                 + sumRight - median * (long long)right.size();
        }
    };


    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        SlidingMedian sm(x);

        vector<long long> costs;

        // Build first window
        for(int i = 0; i < x; i++) {
            sm.add(nums[i]);
        }

        sm.rebalance();

        // Calculate every window cost
        for(int i = 0; i <= n - x; i++) {

            costs.push_back(sm.getCost());

            if(i == n - x) break;

            // Remove outgoing element
            sm.remove(nums[i]);

            // Add incoming element
            sm.add(nums[i + x]);

            // Balance after both updates
            sm.rebalance();
        }

        // DP
        const long long INF = 1e18;

        vector<vector<long long>> dp(
            k + 1,
            vector<long long>(n + 1, INF)
        );

        for(int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for(int j = 1; j <= k; j++) {

            for(int i = 1; i <= n; i++) {

                // Skip current element
                dp[j][i] = dp[j][i - 1];

                // Select window ending at i-1
                if(i >= x && dp[j - 1][i - x] != INF) {

                    long long take =
                        dp[j - 1][i - x] + costs[i - x];

                    dp[j][i] = min(dp[j][i], take);
                }
            }
        }

        return dp[k][n];
    }
};
