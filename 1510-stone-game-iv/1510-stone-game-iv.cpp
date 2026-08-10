class Solution {
public:

    bool helper(int n, bool flag,vector<int>&dp)
    {
        if(n == 0)
            return false;
        if(dp[n]!=-1) return dp[n];
        bool take = false;

        for(int i=1; i*i<=n; i++)
        {
            take = take || !helper(n-i*i, !flag ,dp);
        }

        return dp[n]= take;
    }

    bool winnerSquareGame(int n)
    {
        vector<int>dp(n+1,-1);
        return helper(n, true ,dp);
    }
};