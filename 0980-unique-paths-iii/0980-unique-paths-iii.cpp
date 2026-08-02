class Solution {
public:
    int helper(vector<vector<int>>&grid,int i,int j,int ei,int ej,int z,vector<vector<int>>&vis)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n) return 0;
        if(grid[i][j] == -1 || vis[i][j])return 0;
    
        if( i==ei && j==ej) return z==0 ;
        vis[i][j]=1;
        int left=helper(grid,i,j-1,ei,ej,z-1,vis);
        int right=helper(grid,i,j+1,ei,ej,z-1,vis);
        int up=helper(grid,i-1,j,ei,ej,z-1,vis);
        int down=helper(grid,i+1,j,ei,ej,z-1,vis);
        vis[i][j]=0;
        return up+right+left+down;

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int zero=1;//start wala aise hi count
        int si=0;
        int sj=0;
        int ei=0;
        int ej=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0) zero++;
                if(grid[i][j]==1)
                {
                    si=i;
                    sj=j;
                }
                else if(grid[i][j]==2)
                {
                    ei=i;
                    ej=j;
                }
            }
        }
        int ans=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        return helper(grid,si,sj,ei,ej,zero,vis);
    }
};