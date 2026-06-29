class Solution {
public:
    bool helper(vector<int>&arr,int idx ,vector<int>&dp) 
    {
        if(idx>=arr.size()-1) return true;
        
        if(dp[idx]!=-1) return dp[idx];
        int x=arr[idx];
        bool flag=false;
        for(int i=1;i<=x;i++)
        {
            
            flag=flag || helper(arr,idx+i ,dp);
           
            if(flag) break;
        }
        
        return dp[idx]=flag;
        
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size()-1,-1);
        return helper(nums,0,dp);
        
    }
};