class Solution {
public:
    int helper(vector<int>&nums,int idx,vector<int>&dp)
    {
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        // rob this 
        int rob=nums[idx]+helper(nums,idx+2,dp);
        // leave this
        int leave=helper(nums,idx+1,dp);

        return dp[idx]= max(rob,leave);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return helper(nums,0,dp);
        
    }
};