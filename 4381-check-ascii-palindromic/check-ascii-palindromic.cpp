class Solution {
public:
    bool isPalindrome(string s){
        int low = 0 ,high = s.size() -1;
        while (low < high){
            if (s[low] != s[high]) return false;
            low++; high--;
        }
        return true;
    }
    bool isPalindromic(string s) {
        string res;
        for (char c : s){
            bitset<8> binary(c);
            res += binary.to_string();
        }

        if (isPalindrome(res)) return true;
        return false;
    }
};