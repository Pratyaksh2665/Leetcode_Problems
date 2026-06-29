class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n=patterns.size();
        int ans=0;
        int l=word.length();
       
        for(auto it:patterns)
        {
            string s = it;
            int p=s.length();
            string t="";
            int i=0;
            int j=0;
            while(j<l)
            {
                t+=word[j];
                
                if(j-i+1 == p)
                {
                    if(t==s)
                    {
                        ans++;
                        break;
                    }
                    i++;
                   
                    t=t.substr(1);
                }
                j++;
            }
        }
        return ans;
    }
};