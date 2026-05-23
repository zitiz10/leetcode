class Solution {
public:
    long long dividePlayers(vector<int>& s) {
        sort(s.begin(),s.end());
        int n = s.size();
        int totals=s[0]+s[n-1];
        long long chemsum = 0;
        for(int i=0;i<n/2;i++){
            int currentsum=s[i]+s[n-i-1];
            if(currentsum!=totals)return -1;
            chemsum+= s[i]*s[n-i-1];
        }
        return chemsum;
    }
};