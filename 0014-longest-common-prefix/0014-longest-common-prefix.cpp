class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        string s1=strs[0];
        string s2=strs[n-1];
        int x=s1.length();
        int y=s2.length();
        string ans="";
        int i=0;
        while(s1[i]==s2[i]&&i<min(x,y))
        {
            ans+=s1[i];
            i++;
        }
        return ans;
    }
};