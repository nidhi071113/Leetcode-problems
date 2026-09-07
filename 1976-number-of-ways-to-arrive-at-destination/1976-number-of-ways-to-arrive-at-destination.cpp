class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Create an adjacency list for the graph storing {node, weight}
        vector<pair<int, int>> adj[n];
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Min-heap priority queue storing {distance, node}
        priority_queue<pair<long long, int>, 
                       vector<pair<long long, int>>, 
                       greater<pair<long long, int>>> pq;

        // Distance and ways arrays initialized
        vector<long long> dist(n, 1e18);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        int mod = (int)(1e9 + 7);

        while (!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                int adjNode = it.first;
                long long edW = it.second;

                // This is the first time we are arriving with this short distance
                if (dis + edW < dist[adjNode]) {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});
                    ways[adjNode] = ways[node];
                } 
                // We have encountered another path with the same shortest distance
                else if (dis + edW == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};