class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<int>>&arr)
    {
        int m=arr.size();
        int n=arr[0].size();
        
        vis[r][c]=1;
        
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        
        for(int k=0;k<4;k++)
        {
            int nrow=r+dr[k];
            int ncol=c+dc[k];
            
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n)
            {
                if(!vis[nrow][ncol] && arr[nrow][ncol]==1)
                {
                    dfs(nrow,ncol,vis,arr);
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& arr) {

        int m=arr.size();
        int n=arr[0].size();
        
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        for(int j = 0; j < n; j++) {
            if(arr[0][j] == 1) dfs(0, j, vis, arr);
            if(arr[m-1][j] == 1) dfs(m-1, j, vis, arr);
        }

        
        for(int i = 0; i < m; i++) {
            if(arr[i][0] == 1) dfs(i, 0, vis, arr);
            if(arr[i][n-1] == 1) dfs(i, n-1, vis, arr);
        }

        
        int count=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j]&&arr[i][j]==1)
                {
                    count++;
                }
            }
        }
        return count;
        
        
    }
};