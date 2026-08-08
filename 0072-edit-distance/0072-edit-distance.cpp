class Solution {
public:
    int helper(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
	{
		int n1 = s1.length();
		int n2 = s2.length();
		if (i < 0)
			return j + 1;
		
		if (j < 0)
			return i + 1;
		if (dp[i][j] != -1)
			return dp[i][j];
		int del = 0;
		int replace = 0;
		int insert = 0;
		if (s1[i] == s2[j])
			{
			return dp[i][j] = helper(s1, s2, i - 1, j - 1, dp);
		}
		else
			{
			// delete
			del = 1 + helper(s1, s2, i - 1, j, dp);
			replace = 1 + helper(s1, s2, i - 1, j - 1, dp);
			insert = 1 + helper(s1, s2, i, j - 1, dp);
		}
		return dp[i][j] = min(del, min(replace,insert));
	}
    int minDistance(string s1, string s2) {
        int n1 = s1.length();
		int n2 = s2.length();
		
		if (n1 >= n2)
			{
			vector<vector<int>> dp(n1, vector<int>(n2, -1));
			return helper(s1, s2, n1 - 1, n2 - 1, dp);
		}
		vector<vector<int>> dp(n2, vector<int>(n1, -1));
		return helper(s2, s1, n2 - 1, n1 - 1, dp);
    }
};