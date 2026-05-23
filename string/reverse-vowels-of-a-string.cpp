class Solution {
public:
    string reverseVowels(string s) {
        int n=s.size();
        int j=0;
        int k=n-1;
        while(j<k){
            while(j<k&& !isvowel(s[j])) j++;
            while(j<k&& !isvowel(s[k])) k--;
            swap(s[j],s[k]);
            j++;
            k--;
        }
        return s;
    }
    private: 
      bool isvowel(char c){
        c=tolower(c);
        return(c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
      }
};