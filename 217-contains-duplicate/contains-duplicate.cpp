class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> visited;
        for (int x : nums) {
            if (visited.count(x))
                return true;
            visited.insert(x);
        }
        return false;
    }
};