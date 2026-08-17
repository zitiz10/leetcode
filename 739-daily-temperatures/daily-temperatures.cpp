class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> stk;
        vector<int> ans(temp.size(), 0);
        for (int i = 0; i < temp.size(); i++) {
            while (!stk.empty() && temp[i] > temp[stk.top()]) {
                int pre = stk.top();
                ans[pre] = i - pre;
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};