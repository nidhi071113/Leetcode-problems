class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        /*low  → minimum possible '('
        high → maximum possible '('*/

        for(char c : s) {
            if(c == '(') {
                low++;
                high++;
            }
            else if(c == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;   // treat * as ')'
                high++;  // treat * as '('
            }

            if(high < 0)
                return false;

            if(low < 0)
                low = 0;
        }

        return low == 0;
    }
};