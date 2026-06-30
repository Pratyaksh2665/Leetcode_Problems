
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int ans=0;
        unordered_map<char,int>mp;
        int i=0;
        for(int j=0;j<n;j++)
        {
            mp[s[j]]++;
            while(mp.size()==3)
                {
                    mp[s[i]]--;
                    ans+=(n-j);
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
         

        }
        return ans;
        

    }
};

// these substrings are all valid:as contain a,b,as well as c

// [i..j]
// [i..j+1]
// [i..j+2]
// ...
// [i..n-1]


// Number of them:

// n - j