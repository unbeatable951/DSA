class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> q;

        int fresh=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    fresh++;
                }
                else if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }

        int mins=0;
        vector<int> dir = {-1,0,1,0,-1};
        while(!q.empty() && fresh>0)
        {
            int size=q.size();

            for(int i=0;i<size;i++)
            {
                auto[r,c]=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nr = r + dir[i];
                    int nc = c+ dir[i+1];

                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1)
                    {
                        grid[nr][nc]=2;
                        fresh--;
                        q.push({nr,nc});
                    }
                }
            }
            mins++;
        }

        return fresh==0 ? mins : -1;
        
    }
};