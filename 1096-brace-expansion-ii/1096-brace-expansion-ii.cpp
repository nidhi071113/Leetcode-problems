class Solution {
public:
    string s;
    int i = 0;

    set<string> solve() {
        set<string> ans;
        set<string> cur = {""};

        while(i < s.size() && s[i] != '}') {
            set<string> part;

            if(s[i] == '{') {
                i++;
                part = solve();
                i++;
            }
            else if(s[i] == ',') {
                i++;
                ans.insert(cur.begin(), cur.end());
                cur = {""};
                continue;
            }
            else {
                part.insert(string(1, s[i]));
                i++;
            }

            set<string> temp;

            for(string a : cur) {
                for(string b : part) {
                    temp.insert(a + b);
                }
            }

            cur = temp;
        }

        ans.insert(cur.begin(), cur.end());

        return ans;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;

        set<string> ans = solve();

        return vector<string>(ans.begin(), ans.end());
    }
};