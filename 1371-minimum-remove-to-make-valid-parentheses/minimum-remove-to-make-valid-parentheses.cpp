class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int>stk;
        for(int i =0;i<s.length();i++){
            if(s[i]=='('){
                stk.push_back(i);
            }
            else if (s[i]==')'){
                if(!stk.empty()){
                    stk.pop_back();
                }
                else s[i]='*';
            }
        }
        for(int i : stk){
            s[i]='*';
        }
        string result = "";
        for(char c : s){
            if(c!='*'){
                result +=c;
            }
        }
        return result;
    }
};