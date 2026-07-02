class Solution {
public:
    bool check(vector<vector<int>>& grid, int i, int j, int health,
               vector<vector<bool>>& vis,
               vector<vector<vector<int>>>& dp)
    {
        if (grid[i][j] == 1)
            health--;

        if (health <= 0)
            return false;

        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return true;

        if (dp[i][j][health] != -1)
            return dp[i][j][health];

        vis[i][j] = true;

        int row[4] = {-1, 1, 0, 0};
        int col[4] = {0, 0, -1, 1};

        bool ans = false;

        for (int k = 0; k < 4; k++)
        {
            int nrow = i + row[k];
            int ncol = j + col[k];

            if (nrow >= 0 && nrow < grid.size() &&
                ncol >= 0 && ncol < grid[0].size() &&
                !vis[nrow][ncol])
            {
                ans |= check(grid, nrow, ncol, health, vis, dp);
            }
        }

        vis[i][j] = false;  

        return dp[i][j][health] = ans;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(health + 1, -1)));

        return check(grid, 0, 0, health, vis, dp);
    }
};