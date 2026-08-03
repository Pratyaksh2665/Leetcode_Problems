// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n=s.length();
//         int count=0;
//         unordered_map<char,int>mp;
//         int i=0,j=0,mx=0;
//         while(j<n)
//         {
//             mp[s[j]]++; // ye to sbke liye hoga
//             count++;

//             while(count > mp.size())
//             {
//                 mp[s[i]]--;
//                 count--;
//                 if(mp[s[i]]==0)
//                 {
//                      mp.erase(s[i]);
                     
//                 }
//                 i++;
//             }
//             if(count==mp.size())
//             {
//                 mx=max( mx,j-i+1);
                
                   
//             }
//             j++;
//         }
//         return mx;

        
//     }
// };

// m2 - more clear
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char,int> mp;
        int i = 0, mx = 0;

        for(int j = 0; j < s.size(); j++)
        {
            mp[s[j]]++;

            // if duplicate appears, shrink
            while(mp[s[j]] > 1)
            {
                mp[s[i]]--;
                i++;
            }

            mx = max(mx, j - i + 1);
        }

        return mx;
    }
};
