class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        unordered_map<string, string> mp;
        for (const auto& pair : knowledge) {
            mp[pair[0]] = pair[1];
        }

        string ans = "";
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                string key = "";
                i++; 

                while (i < n && s[i] != ')') {
                    key += s[i];
                    i++;
                }

                if (mp.count(key)) {
                    ans += mp[key];
                } else {
                    ans += '?';
                }
            } else {
                ans += s[i];
            }
        }

        return ans;
    }
};