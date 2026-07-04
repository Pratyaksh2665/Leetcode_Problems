class Solution {
public:
     void dfs(vector<vector<int>>& grid ,int i,int j ,vector<vector<int>>&vis, long long &count)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(vis[i][j]) return;
        count+=grid[i][j];
        vis[i][j]=1;

        int row[4]={-1,1,0,0};
        int col[4]={0,0,-1,1};

        for(int k=0;k<4;k++)
        {
            int nrow = i+row[k];
            int ncol = j+col[k];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]!=0 && !vis[nrow][ncol] )
            {
                dfs(grid , nrow , ncol , vis,count);
            }

        }
        return;

    }
    int findMaxFish(vector<vector<int>>& grid) {
         int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        int maxm = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!=0 && !vis[i][j])
                {
                    long long count=0;
                    dfs(grid , i , j , vis ,count);
                    if(count > maxm) maxm = count;
                }

            }
        }
        return maxm;
    }
};