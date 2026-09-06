class Solution {
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;
    string bWord;

    void dfs(string word, vector<string>& seq) {
        if (word == bWord) {
            vector<string> dup = seq;
            reverse(dup.begin(), dup.end());
            ans.push_back(dup);
            return;
        }
        
        int steps = mpp[word];
        for (int i = 0; i < word.size(); i++) {
            char original = word[i];
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                if (mpp.count(word) && mpp[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        
        q.push(beginWord);
        mpp[beginWord] = 1;
        st.erase(beginWord);
        bWord = beginWord;

        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int steps = mpp[word];

            if (word == endWord) break;

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (st.count(word)) {
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }

        if (mpp.count(endWord)) {
            vector<string> seq = {endWord};
            dfs(endWord, seq);
        }

        return ans;
    }
};