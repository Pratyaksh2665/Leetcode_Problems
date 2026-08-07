class Solution {
public:
    bool helper(vector<int>&nums , int i,int sum,vector<vector<int>>&dp)
    {
        if(sum==0) return true;
        if(i>=nums.size() && sum!=0) return false;
        
        if(nums[i]>sum) return dp[i][sum]=helper(nums,i+1,sum,dp);
        if(dp[i][sum]!=-1) return dp[i][sum];
        //take 
        bool take = helper(nums,i+1,sum-nums[i],dp);
        //leave
        bool leave = helper(nums,i+1,sum,dp);
    

        return dp[i][sum] = take || leave;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums) sum+=it;
        if(sum%2 !=0) return false;
        vector<vector<int>>dp(n,vector<int>(sum/2 + 1 , -1));
        return helper(nums,0,sum/2,dp);
    }
};