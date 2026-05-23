class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n=nums.size();
        vector<int>even;
        vector<int>odd;
        
        for(int i=0;i<n;i++){
            if(i%2==0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        sort(even.begin(),even.end());
        sort(odd.rbegin(),odd.rend());

        vector<int>res;
        int p=0,q=0;

        for(int j=0;j<n;j++){
            if(j%2==0) res.push_back(even[p++]);
            else res.push_back(odd[q++]);
        }
        return res;
    }
};