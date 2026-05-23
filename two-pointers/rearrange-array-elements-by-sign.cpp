class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>pos;
        vector<int>negi;
        for(int i=0;i<n;i++){
            if(nums[i]>0) pos.push_back(nums[i]);
            else negi.push_back(nums[i]);
        }
        int p=0,q=0;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(i%2==0) ans.push_back(pos[p++]);
            else ans.push_back(negi[q++]);
        }
        return ans;
    }
};