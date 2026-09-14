class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
private:
    bool isValid(int newRow, int newCol, int n) {
        return newRow >= 0 && newRow < n && newCol >= 0 && newCol < n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Step 1: Connect all initial 1s in the grid using DSU
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) continue;

                for (int ind = 0; ind < 4; ind++) {
                    int newRow = row + dr[ind];
                    int newCol = col + dc[ind];

                    if (isValid(newRow, newCol, n) && grid[newRow][newCol] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newRow * n + newCol;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        // Step 2: Try converting every 0 to a 1 and measure maximum island size
        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;

                set<int> components;
                for (int ind = 0; ind < 4; ind++) {
                    int newRow = row + dr[ind];
                    int newCol = col + dc[ind];

                    if (isValid(newRow, newCol, n) && grid[newRow][newCol] == 1) {
                        components.insert(ds.findUPar(newRow * n + newCol));
                    }
                }

                int sizeTotal = 1; // 1 for the zero converted to one
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal);
            }
        }

        // Step 3: Corner case - if the grid contains only 1s
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            mx = max(mx, ds.size[ds.findUPar(cellNo)]);
        }

        return mx;
    }
};