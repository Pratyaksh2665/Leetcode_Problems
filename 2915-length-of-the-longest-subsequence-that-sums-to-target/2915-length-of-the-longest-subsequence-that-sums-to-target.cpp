class Solution {
public:
    int helper(vector<int>&nums,int target,int idx,vector<vector<int>>&dp)
    {
        if(target==0) return 0;
        if(idx>=nums.size()) return INT_MIN;

        if(dp[idx][target]!=-1) return dp[idx][target];
        
        int skip=helper(nums,target,idx+1,dp);
        if(nums[idx]>target) return dp[idx][target]=skip;
        int take=1+helper(nums,target-nums[idx],idx+1,dp);

        return dp[idx][target]=max(take,skip);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));

        int x=helper(nums,target,0,dp);
        if(x>0) return x;
        return -1;
        
    }
};