class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if(n<=1) return 1;
        vector<int>m(n);
        vector<int>p(n);
        m[0]=1;
        p[n-1]=1;
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1]) m[i]=(1+m[i-1]);
            else m[i]=1;
        }

        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1]) p[i]=(1+p[i+1]);
            else p[i]=1;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=max(p[i],m[i]);
        }
        return ans;
        
    }
};