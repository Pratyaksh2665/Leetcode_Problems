// class Solution {
// public:
//     int helper(int i,int j,int m,int n,vector<vector<int>>&dp)
//     {
//         if(i==m-1 && j==n-1) return 1;
//         if(i>=m || j>=n) return 0;
//         if(i<m && j<n && dp[i][j]!=-1) return dp[i][j];
//         // right 
//         int right =0;
//         if(j<n)
//         {
//             right=helper(i,j+1,m,n,dp);
//         }
//         //down
//         int down=0;
//         if(i<m)
//         {
//             down=helper(i+1,j,m,n,dp);
//         }

//         return dp[i][j]=right+down;
//     }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         return helper(0,0,m,n,dp);
//     }
// };
//m2-
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            dp[i][0]=1;

        }
        for(int i=0;i<n;i++)
        {
            dp[0][i]=1;
            
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};