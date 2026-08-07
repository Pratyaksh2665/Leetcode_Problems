class Solution {
public:
    int helper(int n,vector<int>&dp)
    {
        if(n==0) return 0;
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        int x=sqrt(n);
        if(x*x == n) return 1;
        int minm=INT_MAX;
        for(int i=1;i<=x;i++)
        {
            int p=1+helper(n-(i*i),dp);
            minm=min(minm,p);
        }
        return dp[n]=minm;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};