class Solution {
public:
    int minInsertions(string s) {
        int bal=0;
        int ans=0;

        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                bal++;
            }
            else {
                if(i+1 < s.length() && s[i+1] == ')'){
                    i++;
                }
                else{
                    ans++;
                }

                if(bal > 0){
                    bal--;
                }
                else{
                    ans++;
                }
            }
        }
        return ans+bal*2;
    }
};