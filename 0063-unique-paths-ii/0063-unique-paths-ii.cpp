class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m=arr.size();
        int n=arr[0].size();
        if(arr[0][0]==1 || arr[m-1][n-1]) return 0;
        // if(n==1 || m==1) return 1;
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            if(arr[0][i]!=1)dp[0][i]=1;
            else break;
        }
        for(int i=0;i<m;i++)
        {
            if(arr[i][0]!=1)dp[i][0]=1;
            else break;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(arr[i][j]!=1)
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }

            }
        }
        return dp[m-1][n-1];
    }
};