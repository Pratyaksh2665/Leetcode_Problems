class Solution {
public:
    long long helper(vector<int>&coins , int i ,  int amt,vector<vector<int>>&dp)
    {
        if(amt==0) return 0;
        if(i >= coins.size()) return INT_MAX;

        if(dp[i][amt]!=-1) return dp[i][amt];
        if(amt < coins[i]) return dp[i][amt]= helper(coins,i+1,amt,dp);

        //take
        long long take =1+ helper(coins , i , amt-coins[i],dp);
        //leave
        long long leave =  helper(coins , i+1 , amt,dp);

        return dp[i][amt]= min(take,leave);
    }
    int coinChange(vector<int>& coins, int amt) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amt+1,-1));
        if(helper(coins,0,amt,dp)!=INT_MAX) return (int)helper(coins,0,amt,dp);
        return -1; 
    }
};