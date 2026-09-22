class Solution {
public:
    bool checkValidString(string s) {
        int cntMin = 0/*keep track of * assumes all * to be ( */, cntMax = 0/* assume * to be )*/;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(') {
                cntMin++;
                cntMax++;
            }
            else if(s[i] == ')') {
                cntMin--;
                cntMax--;
            }
            else{
                cntMin--;
                cntMax++;
            }
            if(cntMin < 0) cntMin=0;
            if(cntMax < 0) return false;
        }

        return cntMin == 0;
    }
};