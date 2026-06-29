class Solution {
public:
    bool helper(vector<int>&arr , int idx ,vector<int>&dp)
    {
        
        if(idx<0 || idx>arr.size()-1) return false;

        if(arr[idx]==0) return true;

        if(dp[idx]!=-1) return dp[idx];

        dp[idx]=0; //temporarily isko maana ki visited h it prevent cycles

        bool forward = helper(arr,idx+arr[idx],dp);

        bool backward = helper(arr , idx-arr[idx] , dp);

        return dp[idx] = forward || backward;
 
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();

        vector<int>dp(n,-1);

        return helper(arr , start , dp);
        
    }
};