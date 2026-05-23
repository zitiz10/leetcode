class Solution {
public:
    string reversePrefix(string s, int k) {
        int i=0;
            while(i<k){
                if(k!=0){
                    swap(s[i],s[k-1]);
                    i++;
                    k--;
                }
            }
            return s;
    }
};