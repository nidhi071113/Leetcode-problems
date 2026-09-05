class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        //create adj list
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        //calc indegree arr
        vector<int> indegree(numCourses,0);

        for(int i=0;i<numCourses;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        //putting indegree = 0 in to nodes
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0) q.push(i);
        }

        int cnt = 0; //counts how many courses we can complete
        while(!q.empty()){
            int node = q.front();
            q.pop();

            cnt++;

            //remove the nodes from graph and decrease the degree from the adjacent nodes
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        //this tell whether there is cycle
        if(cnt == numCourses) return true;

        return false;
    }
};