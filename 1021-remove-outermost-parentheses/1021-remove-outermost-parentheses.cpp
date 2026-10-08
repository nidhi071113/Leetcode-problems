class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int bal=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                if(bal>0) res+=s[i];
                bal++;
            }
            else{
                bal--;
                if(bal>0) res+=s[i];
            }
        }
        return res;
    }
};