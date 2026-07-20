class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();

        vector<int>v;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                v.push_back(grid[i][j]);
            }
        }
        k=k%(m*n);
        reverse(v.begin(),v.end());
        reverse(v.begin(),v.begin()+k);
        reverse(v.begin()+k,v.end());

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int idx = i * n + j;
                grid[i][j]=v[idx];
            }
        }
        return grid;
    }
};