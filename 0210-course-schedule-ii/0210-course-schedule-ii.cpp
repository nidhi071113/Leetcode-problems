class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        // create adjacency list
        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        // calculate indegree
        vector<int> indegree(numCourses,0);
        for(int i = 0; i < numCourses; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // put all nodes with indegree 0 into queue
        queue<int> q;

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            // store course in topological order
            topo.push_back(node);
            // decrease indegree of neighbours
            for(auto it : adj[node]) {

                indegree[it]--;

                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // if all courses are processed
        if(topo.size() == numCourses) {
            return topo;
        }

        // cycle exists, so impossible to finish all courses
        return {};
    }
};