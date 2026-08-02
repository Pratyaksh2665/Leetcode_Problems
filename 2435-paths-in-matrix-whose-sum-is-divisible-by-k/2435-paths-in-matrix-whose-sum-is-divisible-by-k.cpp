class Solution {
public:
    int mod = 1e9 + 7;

    int helper(vector<vector<int>>& grid, int i, int j, int k, int rem,
               vector<vector<vector<int>>>& dp)
    {
        int m = grid.size();
        int n = grid[0].size();

        if(i >= m || j >= n) return 0;

        rem = (rem + grid[i][j]) % k;

        if(dp[i][j][rem] != -1)
            return dp[i][j][rem];

        if(i == m-1 && j == n-1)
        {
            return rem == 0;
        }

        int right = helper(grid, i, j+1, k, rem, dp);
        int down  = helper(grid, i+1, j, k, rem, dp);

        return dp[i][j][rem] = (right + down) % mod;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(n, vector<int>(k, -1))
        );

        return helper(grid, 0, 0, k, 0, dp);
    }
};