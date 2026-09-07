class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //created adj list
        vector<vector<pair<int,int>>> adj(n+1);
        for(const auto &time : times){
            adj[time[0]].push_back({time[1],time[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(n+1,1e9);
        dist[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            auto[d,node] = pq.top();
            pq.pop();

            if(d > dist[node]) continue;

            for(auto& edge : adj[node]){
                int neighbor = edge.first;
                int weight = edge.second;

                if(dist[node] + weight < dist[neighbor]){
                    dist[neighbor] = dist[node] + weight;
                    pq.push({dist[neighbor],neighbor});
                }
            }
        }

        int maxTime = 0;
        for(int i=1;i<=n;i++){
            if(dist[i] == 1e9) return -1;
            maxTime = max(maxTime,dist[i]);
        }
        return maxTime;
    }
};