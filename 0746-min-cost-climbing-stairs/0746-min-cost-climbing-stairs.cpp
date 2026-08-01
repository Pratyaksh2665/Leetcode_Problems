class Solution {
public:
    int helper(vector<int>&cost,int idx,vector<int>&dp)
    {
        if(idx>=cost.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        //one step
        int one = cost[idx]+helper(cost,idx+1,dp);
        //two step 
        int two = cost[idx]+helper(cost,idx+2,dp);

        return dp[idx]=min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {

        if(cost.size()==1) return cost[0];
        vector<int>dp(cost.size(),-1);
        return min(helper(cost,0,dp),helper(cost,1,dp));
    }
};