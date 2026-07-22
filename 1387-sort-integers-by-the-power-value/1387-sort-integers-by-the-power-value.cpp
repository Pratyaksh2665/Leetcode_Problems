class Solution {
public:
    int power(int n)
    {
        if(n==1) return 0;
        if(n%2==0) return 1+power(n/2);
        else return 1+power(3*n+1);
    }
    int getKth(int lo, int hi, int k)
    {
        vector<pair<int,int>>v;
        for(int i=lo;i<=hi;i++)
        {
            v.push_back({power(i),i});
        }
        sort(v.begin(),v.end());

        return v[k-1].second;
        
    }
};