class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int n = grid.size();

        // Start or destination blocked
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        queue<pair<int,int>> q;

        vector<vector<int>> dist(n, vector<int>(n, -1));

        // Start BFS
        q.push({0, 0});
        dist[0][0] = 1;

        // 8 directions
        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty())
        {
            auto [r,c] = q.front();
            q.pop();

            // Destination reached
            if(r == n-1 && c == n-1)
                return dist[r][c];

            for(int d = 0; d < 8; d++)
            {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < n &&
                   grid[nr][nc] == 0 &&
                   dist[nr][nc] == -1)
                {
                    dist[nr][nc] = dist[r][c] + 1;

                    q.push({nr,nc});
                }
            }
        }

        return -1;
    }
};