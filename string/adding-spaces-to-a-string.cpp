class Solution {
public:
    string addSpaces(string s, vector<int>&arr) {
        int i=0;
        string ans="";
        for(int j=0;j<s.size();j++){
            if(i<arr.size()&& j==arr[i]){
                ans+=" ";
                i++;
            }
            ans+=s[j];
        }
        return ans;

    }
};