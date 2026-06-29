class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int c=s.size();

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int ans=0;

        int j=c-1;
        for(int i=n-1;i>=0;i--)
        {
            if(j>=0)
            {
                if(g[i]<=s[j]) 
                {
                    ans++;
                    j--;
                    
                }
            }
        }

        return ans;

    }
};