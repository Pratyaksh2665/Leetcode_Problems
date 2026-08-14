class Solution {
public:
    int helper(vector<vector<int>>& triangle, int i, int j,
               vector<vector<int>>& dp)
    {
        int m = triangle.size();

        if(i == m-1)return triangle[i][j];
            

        int n = triangle[i].size();

        if(j >= n)return 1e9;
            

        if(dp[i][j] != INT_MAX)return dp[i][j];
            

        int first = helper(triangle, i+1, j, dp);
        int second = helper(triangle, i+1, j+1, dp);

        return dp[i][j] =triangle[i][j] + min(first, second);
            
    }

    int minimumTotal(vector<vector<int>>& triangle)
    {
        int m = triangle.size();
        int n = triangle[m-1].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

        return helper(triangle, 0, 0, dp);
    }
};