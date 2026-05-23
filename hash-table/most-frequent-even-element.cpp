class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int>mp;
        for(auto n:nums) {
            if(n%2==0) mp[n]++;
        }
        int ans= -1,max =-1;
        for(auto m: mp){
            if( m.second>max){
                max=m.second;
                ans=m.first;
            }
        }
        return ans;
    }
};