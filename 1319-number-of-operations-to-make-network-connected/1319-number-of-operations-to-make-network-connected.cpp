class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]); // Path Compression
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // Step 1: Minimum edges required to connect n nodes is n - 1
        if (connections.size() < n - 1) return -1;

        DisjointSet ds(n);

        // Step 2: Union connected computers
        for (auto& edge : connections) {
            ds.unionByRank(edge[0], edge[1]);
        }

        // Step 3: Count connected components (unique ultimate parents)
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findUPar(i) == i) {
                components++;
            }
        }

        // Minimum operations needed to connect all components
        return components - 1;
    }
};