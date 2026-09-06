class Solution {
public:

    int helper(string &s, string &t, int i, int j,vector<vector<int>>&dp)
    {
        if(j == t.length())
            return 1;

        if(i == s.length())
            return 0;
            
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i] == t[j])
        {
            int take = helper(s, t, i+1, j+1,dp);
            int leave = helper(s, t, i+1, j,dp);

            return dp[i][j] = take + leave;
        }
        else
        {
            return dp[i][j] = helper(s, t, i+1, j,dp);
        }
    }

    int numDistinct(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return helper(s, t, 0, 0,dp);
    }
};