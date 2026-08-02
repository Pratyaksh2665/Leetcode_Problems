class Solution {
public:
    // int helper(int n)
    // {
    //     if(n<=0) return 0;
    //     //one step
    //     int one = 1+helper(n-1);
    //     //two step 
    //     int two = 1+helper(n-2);

    //     return one+two;
    // }
    int climbStairs(int n) {
        // if(n==1) return 1;
        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=1;
        if(n>=2)dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};