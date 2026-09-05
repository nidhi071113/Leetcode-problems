class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adjRev(V);
        vector<int> indegree(V, 0);

        // Step 1: Reverse graph edges & calculate indegrees for reversed graph
        for (int i = 0; i < V; i++) {
            // i -> it in original graph
            // it -> i in reversed graph
            for (auto it : graph[i]) {
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }

        // Step 2: Push all terminal nodes (indegree == 0 in reversed graph) to Queue
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: Perform BFS (Kahn's Algorithm)
        vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for (auto it : adjRev[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // Step 4: Sort safe nodes in ascending order as required
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};