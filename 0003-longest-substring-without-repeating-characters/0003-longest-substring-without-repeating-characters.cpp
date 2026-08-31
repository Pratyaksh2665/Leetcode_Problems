class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int maxm=0;
        while(j<n)
        {
            mp[s[j]]++;
            if(j-i+1 == mp.size())
            {
                maxm = max(maxm , j-i+1);

            }
            else
            {
                while(mp.size()!=j-i+1)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)mp.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        return maxm;
    }
};