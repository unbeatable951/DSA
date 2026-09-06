class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> distance(n,vector<int>(m,-1));

        queue<pair<int,int>>bfs;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    distance[i][j]=0;
                    bfs.push({i,j});
                }
            }
        }

        vector<int>direction = {-1,0,1,0,-1};

        while(!bfs.empty())
        {
            auto[r,c]=bfs.front();
            bfs.pop();

            for(int i=0;i<4;i++)
            {
                int nextrow= r + direction[i];
                int nextcol = c+ direction[i+1];

                if(nextrow>=0 && nextrow<n && nextcol>=0 
                && nextcol<m && distance[nextrow][nextcol]==-1)
                {
                    distance[nextrow][nextcol]= distance[r][c] + 1;
                    bfs.push({nextrow,nextcol});
                }
            }

        }

        return distance;
        
    }
};