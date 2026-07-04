class Solution {
public:
    void dfs(vector<vector<char>>& grid ,int i,int j ,vector<vector<int>>&vis)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(vis[i][j]) return;
        vis[i][j]=1;

        int row[4]={-1,1,0,0};
        int col[4]={0,0,-1,1};

        for(int k=0;k<4;k++)
        {
            int nrow = i+row[k];
            int ncol = j+col[k];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]=='1' && !vis[nrow][ncol] )
            {
                dfs(grid , nrow , ncol , vis);
            }

        }
        return;

    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        int count = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    dfs(grid , i , j , vis);
                    count++;
                }

            }
        }
        return count;
    }
};