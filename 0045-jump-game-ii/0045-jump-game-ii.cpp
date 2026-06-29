class Solution {
public:
    int helper(vector<int>& nums,int idx,vector<int>& dp)
{
    if(idx>=nums.size()-1) return 0;

    if(dp[idx]!=-1) return dp[idx];

    int ans=1e9;

    for(int j=1;j<=nums[idx];j++)
    {
        ans=min(ans,1+helper(nums,idx+j,dp));
    }

    return dp[idx]=ans;
}
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        
        return helper(nums , 0 ,dp);

    }
};