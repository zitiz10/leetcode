class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int x : nums)
            mp[x]++;
        int x = 0;
        while (true) {
            x += k;
            if (mp.find(x) == mp.end())
                return x;
        }
        return -1;
    }
};