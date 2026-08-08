class Solution {
public:
    int helper(string &text1, string &text2,int i,int j,vector<vector<int>>&dp)
    {
        int m=text1.length();
        int n=text2.length();
        if(i<0 || j<0) return 0; 
        if(dp[i][j]!=-1) return dp[i][j];
          
        int len=0;
        if(text1[i]==text2[j])
        {
            len=1+helper(text1,text2,i-1,j-1,dp);
        }
        else
        {
            len=max(helper(text1,text2,i,j-1,dp),helper(text1,text2,i-1,j,dp));
        }
        return dp[i][j]=len;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length();
        int n=text2.length();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(text1,text2,m-1,n-1,dp);
    }
};