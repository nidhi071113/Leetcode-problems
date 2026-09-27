class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> st; 

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push_back(i);
            } 
            else if (s[i] == ')') {
                int start = st.back();
                st.pop_back();
                reverse(s.begin() + start + 1, s.begin() + i);
            }
        }

        string ans = "";
        for (char c : s) {
            if (c != '(' && c != ')') {
                ans += c;
            }
        }

        return ans;
    }
};