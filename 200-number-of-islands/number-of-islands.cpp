class Solution {
public:
vector<int> parent, size;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSet(int u, int v, int &count) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return;

        // union by size
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }

        count--; // merging reduces island count
    }
    int numIslands(vector<vector<char>>& grid) {
         int m = grid.size();
        int n = grid[0].size();

        parent.resize(m * n);
        size.resize(m * n, 1);

        // initialize
        for (int i = 0; i < m * n; i++)
            parent[i] = i;

        int count = 0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                }
            }
        }
         vector<pair<int,int>> dirs = {{0,1}, {1,0}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '0') continue;

                int id1 = i * n + j;

                for (auto &d : dirs) {
                    int ni = i + d.first;
                    int nj = j + d.second;

                    if (ni < m && nj < n && grid[ni][nj] == '1') {
                        int id2 = ni * n + nj;
                        unionSet(id1, id2, count);
                    }
                }
            }
        }

        return count;
    }
};