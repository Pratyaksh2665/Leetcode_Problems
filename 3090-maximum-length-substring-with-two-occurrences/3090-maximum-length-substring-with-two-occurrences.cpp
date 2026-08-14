class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.length();
        int i=0;
        int j=0;
        unordered_map<char,int>mp;
        int maxm = 0;
        bool possible = true;
        while(j<n )
        {
            if(possible)
            {
                mp[s[j]]++;
                if(mp[s[j]]>2) 
                {
                    possible = false;
                }
                else {
                    maxm = max(maxm , j-i+1);
                    
                }
                j++;
            }
            else
            {
                while(i<j && s[i]!=s[j-1])
                {
                    mp[s[i]]--;
                    i++;
                }
                mp[s[i]]--;
                i++;
                possible = true;
            }
        }
        return maxm;
    }
};