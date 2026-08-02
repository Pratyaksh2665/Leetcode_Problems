class Solution {
public:
    int countSquares(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    grid[i][j]+=min(grid[i-1][j],min(grid[i][j-1],grid[i-1][j-1]));
                }
                
            }
        }
        int sum=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum+=grid[i][j];
            }
        }
        return sum;
    }
};