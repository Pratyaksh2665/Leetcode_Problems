class Solution {
public:
    int helper(vector<vector<int>>&costs,int idx,int cnt1,int cnt2,vector<vector<int>>&dp)
    {
        if(idx == costs.size())
        {
            if(cnt1 == 0 && cnt2 == 0) return 0;
                
            return 1e7;
        }
        if(dp[idx][cnt1]!=-1) return dp[idx][cnt1];

        int first = 1e7;
        int second = 1e7;

        if(cnt1 > 0)
            first = costs[idx][0] + helper(costs, idx+1, cnt1-1, cnt2, dp);

        if(cnt2 > 0)
            second = costs[idx][1] + helper(costs, idx+1, cnt1, cnt2-1, dp);
        return dp[idx][cnt1]=min(first , second);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n=costs.size();
        vector<vector<int>> dp(n + 1, vector<int>(n/2 + 1, -1));
        return helper(costs,0,n/2,n/2,dp);
    }
};