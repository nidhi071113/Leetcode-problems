class Solution {
private:
    int timer = 1;

    void dfs(int node, int parent, vector<int>& vis, vector<int> adj[], 
             vector<int>& tin, vector<int>& low, vector<vector<int>>& bridges) {
        
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        for (auto it : adj[node]) {
            // Do not traverse back to the parent node
            if (it == parent) continue;

            if (!vis[it]) {
                // DFS traversal for unvisited neighbor
                dfs(it, node, vis, adj, tin, low, bridges);

                // On backtrack, update the lowest insertion time of the current node
                low[node] = min(low[node], low[it]);

                // Check if the edge (node, it) is a bridge
                if (low[it] > tin[node]) {
                    bridges.push_back({node, it});
                }
            } else {
                // If neighbor is already visited and is not parent, it's a back-edge
                low[node] = min(low[node], tin[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Step 1: Build Adjacency List
        vector<int> adj[n];
        for (auto& it : connections) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        vector<int> tin(n);
        vector<int> low(n);
        vector<vector<int>> bridges;

        // Step 2: Perform DFS for all components
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, adj, tin, low, bridges);
            }
        }

        return bridges;
    }
};