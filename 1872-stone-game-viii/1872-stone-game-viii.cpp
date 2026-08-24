class Solution {
public:

    int helper(vector<int>& prefix, int i, vector<int>& dp)
    {
        int n = prefix.size();

        if(i == n-1)
            return prefix[i];

        if(dp[i] != INT_MIN)
            return dp[i];

        int take = prefix[i] - helper(prefix, i+1, dp);

        int skip = helper(prefix, i+1, dp);

        return dp[i] = max(take, skip);
    }

    int stoneGameVIII(vector<int>& stones)
    {
        int n = stones.size();

        vector<int> prefix(n);

        prefix[0] = stones[0];

        for(int i=1; i<n; i++)
        {
            prefix[i] = prefix[i-1] + stones[i];
        }

        vector<int> dp(n, INT_MIN);

        return helper(prefix, 1, dp);
    }
};