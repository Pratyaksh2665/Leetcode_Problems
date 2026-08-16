class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int count=0;
        for(int k=0;k<n;k++)// loop kitni baar chal rha h
        {
            int i=0,j=k;
            while(j<n)
            {
                if(i==j) 
                {
                    dp[i][j]=1;
                    count++;
                }
                else if(j==i+1)
                {
                    if(s[i]==s[j]) 
                    {
                        dp[i][j]=1;
                        count++;
                    }
                }
                else
                {
                    if(s[i]==s[j])
                    {
                        if(dp[i+1][j-1]==1) 
                        {
                            dp[i][j]=1;// phle wala bhi palindrome tha 
                            count++;
                        }
                    }

                }
                i++;
                j++;
            }
            
        }

        return count;
    }
};