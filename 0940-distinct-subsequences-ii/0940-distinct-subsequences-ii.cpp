class Solution {
public:
    int distinctSubseqII(string s) {

        const long long MOD = 1000000007;
        int n = s.length();

        vector<long long> dp(n);

        dp[0] = 2;

        unordered_map<char,int> mp;
        mp[s[0]] = 0;

        for(int i = 1; i < n; i++)
        {
            dp[i] = (2 * dp[i-1]) % MOD;

            if(mp.count(s[i]))
            {
                int j = mp[s[i]];

                if(j == 0)
                    dp[i] = (dp[i] - 1 + MOD) % MOD;
                else
                    dp[i] = (dp[i] - dp[j-1] + MOD) % MOD;
            }

            mp[s[i]] = i;
        }

        return (dp[n-1] - 1 + MOD) % MOD;
    }
};