class Solution {
public:
    // int helper(vector<int>&nums,int target,int idx,vector<vector<int>>&dp)
    // {
    //     if(target==0) return 0;
    //     if(idx>=nums.size()) return INT_MIN;

    //     if(dp[idx][target]!=-1) return dp[idx][target];
        
    //     int skip=helper(nums,target,idx+1,dp);
    //     if(nums[idx]>target) return dp[idx][target]=skip;
    //     int take=1+helper(nums,target-nums[idx],idx+1,dp);

    //     return dp[idx][target]=max(take,skip);
    // }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, INT_MIN));
        for(int i=0;i<n;i++)dp[i][0]=0;
        
        if(nums[0]<=target)dp[0][nums[0]]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                int skip = dp[i-1][j];

                int take = INT_MIN;

                if(nums[i]<=j && dp[i-1][j-nums[i]]!=INT_MIN)
                    take = 1 + dp[i-1][j-nums[i]];

                dp[i][j]=max(skip,take);
            }
        }

        return dp[n-1][target]==INT_MIN ? -1 : dp[n-1][target];
    }
};