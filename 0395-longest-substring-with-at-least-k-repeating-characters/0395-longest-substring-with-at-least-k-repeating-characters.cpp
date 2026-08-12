class Solution {
public:

    int solve(string s, int k) {
        if(s.size() == 0) return 0;

        vector<int> freq(26,0);
        for(char c : s)
            freq[c-'a']++;

        for(int i=0;i<s.size();i++)
        {
            if(freq[s[i]-'a'] < k)
            {
                int left = solve(s.substr(0,i), k);
                int right = solve(s.substr(i+1), k);
                return max(left, right);
            }
        }

        
        return s.size();
    }

    int longestSubstring(string s, int k) {
        return solve(s,k);
    }
};
