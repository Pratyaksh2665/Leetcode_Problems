class Solution {
public:
    // int helper(vector<int>&nums,int idx,vector<int>&dp)
    // {
    //     if(idx>=nums.size()) return 0;
    //     if(dp[idx]!=-1) return dp[idx];
    //     // rob this 
    //     int rob=nums[idx]+helper(nums,idx+2,dp);
    //     // leave this
    //     int leave=helper(nums,idx+1,dp);

    //     return dp[idx]= max(rob,leave);
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n);
        // return helper(nums,0,dp);
        if(n==1) return nums[0];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);

        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return max(dp[n-1],dp[n-2]);
    }
};