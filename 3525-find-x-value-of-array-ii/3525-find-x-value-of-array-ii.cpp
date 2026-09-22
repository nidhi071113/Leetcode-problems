
struct Node {
    int prod;
    int cnt[5];

    Node() {
        prod = 1;
        for (int i = 0; i < 5; ++i) cnt[i] = 0;
    }
};

class SegmentTree {
private:
    int n, k;
    vector<Node> tree;

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.prod = (left.prod * right.prod) % k;

        for (int i = 0; i < k; ++i) {
            res.cnt[i] = left.cnt[i];
        }

        for (int i = 0; i < k; ++i) {
            if (right.cnt[i] > 0) {
                int rem = (left.prod * i) % k;
                res.cnt[rem] += right.cnt[i];
            }
        }

        return res;
    }

    void build(const vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            int val = nums[start] % k;
            tree[node].prod = val;
            tree[node].cnt[val] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        build(nums, 2 * node, start, mid);
        build(nums, 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            int rem = val % k;
            tree[node].prod = rem;
            for (int i = 0; i < k; ++i) tree[node].cnt[i] = 0;
            tree[node].cnt[rem] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (start <= idx && idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return Node();
        if (l <= start && end <= r) return tree[node];

        int mid = start + (end - start) / 2;
        if (r <= mid) return query(2 * node, start, mid, l, r);
        if (l > mid) return query(2 * node + 1, mid + 1, end, l, r);

        Node left = query(2 * node, start, mid, l, r);
        Node right = query(2 * node + 1, mid + 1, end, l, r);
        return merge(left, right);
    }

public:
    SegmentTree(const vector<int>& nums, int K) {
        n = nums.size();
        k = K;
        tree.resize(4 * n);
        build(nums, 1, 0, n - 1);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int start, int targetX) {
        Node ansNode = query(1, 0, n - 1, start, n - 1);
        return ansNode.cnt[targetX];
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        // Fast I/O for competitive performance
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        SegmentTree st(nums, k);

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start = q[2];
            int x = q[3];

            st.update(idx, val);
            ans.push_back(st.query(start, x));
        }

        return ans;
    }
};