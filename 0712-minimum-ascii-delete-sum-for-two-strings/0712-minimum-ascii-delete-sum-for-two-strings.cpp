class Solution {
public:
    int minimumDeleteSum(string s, string t) {
        int m=s.length();
        int n=t.length();

        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=s[i-1]+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }

            }
        }
        string str="";
        int i=m,j=n;
        while(i>0 && j>0)
        {
            if(s[i-1]==t[j-1])
            {
                str+=s[i-1];
                i--;
                j--;
                continue;
            }
            if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }

        int ans1=0;
        for(auto it:s) ans1+=(it-'a'+97);
        int ans2=0;
        for(auto it:t) ans2+=(it-'a'+97);

        return ans1+ans2-2*dp[m][n];
        
        
    }
};