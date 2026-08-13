class Solution {
public:
    struct Node {
        int len, pre, suf, best;
        char left, right;
    };

    vector<Node> tree;
    string str;

    Node merge(Node a, Node b) {
        Node res;
        res.len = a.len + b.len;
        res.left = a.left;
        res.right = b.right;

        res.pre = a.pre;
        if (a.pre == a.len && a.right == b.left) {
            res.pre += b.pre;
        }

        res.suf = b.suf;
        if (b.suf == b.len && a.right == b.left) {
            res.suf += a.suf;
        }

        res.best = max(a.best, b.best);
        if (a.right == b.left) {
            res.best = max(res.best, a.suf + b.pre);
        }

        return res;
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1, str[start], str[start]};
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char val) {
        if (start == end) {
            tree[node] = {1, 1, 1, 1, val, val};
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        str = s;
        int n = s.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);

        int k = queryCharacters.size();
        vector<int> ans(k);

        for (int i = 0; i < k; i++) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].best;
        }

        return ans;
    }
};