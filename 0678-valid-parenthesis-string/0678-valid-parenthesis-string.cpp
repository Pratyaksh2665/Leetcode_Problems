class Solution {
public:
    bool check(string s,int count ,int idx ,vector<vector<int>>&dp)
    {
        if(count<0) return false;
        if(idx>=s.length()) return count==0;

        if(dp[idx][count]!=-1) return dp[idx][count];

        if(s[idx]=='(') return dp[idx][count]=check(s,count+1,idx+1,dp);
        else if(s[idx]==')') return dp[idx][count]= check(s,count-1,idx+1,dp);
        else
        {
            bool first = check(s,count+1,idx+1,dp);
            if(first) return first;

            return dp[idx][count]=check(s,count-1,idx+1,dp) || check(s,count,idx+1,dp);
        }

        return false;
    }
    bool checkValidString(string s) {
        int count=0;
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return check(s,count,0,dp);
    }
};