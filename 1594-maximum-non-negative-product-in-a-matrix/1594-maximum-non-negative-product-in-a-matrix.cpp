class Solution {
public:
    long long mod = 1e9 + 7;

    pair<long long,long long> helper(vector<vector<int>>& grid, int i, int j,
                                     vector<vector<pair<long long,long long>>>& dp,
                                     vector<vector<int>>& vis)
    {
        int m = grid.size();
        int n = grid[0].size();

        if(i >= m || j >= n)
            return {LLONG_MIN, LLONG_MAX};

        if(i == m-1 && j == n-1)
            return {grid[i][j], grid[i][j]};

        if(vis[i][j])
            return dp[i][j];

        vis[i][j] = 1;

        auto right = helper(grid, i, j+1, dp, vis);
        auto down  = helper(grid, i+1, j, dp, vis);

        long long mx = LLONG_MIN;
        long long mn = LLONG_MAX;

        vector<long long> cand;

        if(right.first != LLONG_MIN)
            cand.push_back(1LL * grid[i][j] * right.first);
        if(right.second != LLONG_MAX)
            cand.push_back(1LL * grid[i][j] * right.second);

        if(down.first != LLONG_MIN)
            cand.push_back(1LL * grid[i][j] * down.first);
        if(down.second != LLONG_MAX)
            cand.push_back(1LL * grid[i][j] * down.second);

        for(long long x : cand)
        {
            mx = max(mx, x);
            mn = min(mn, x);
        }

        return dp[i][j] = {mx, mn};
    }

    int maxProductPath(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<long long,long long>>> dp(
            m, vector<pair<long long,long long>>(n));

        vector<vector<int>> vis(m, vector<int>(n, 0));

        auto ans = helper(grid, 0, 0, dp, vis);

        if(ans.first < 0)
            return -1;

        return ans.first % mod;
    }
};