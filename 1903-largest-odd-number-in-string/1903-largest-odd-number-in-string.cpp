class Solution {
public:
    string largestOddNumber(string num) {
        int last = -1;
        for(int i = 0 ; i < num.size() ; i++){
            if((num[i] - '0') % 2 == 1){
                last = i;
            }
        }
        return last == -1 ? "" : num.substr(0,last+1);
    }
};