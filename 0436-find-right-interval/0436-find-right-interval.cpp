class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();

        vector<int>ans(n,-1);
        vector<pair<vector<int>,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({intervals[i],i});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {

                int tgt=v[i].first[1];
                int low=i;
                int high=n-1;
                while(low<=high)
                {
                    int mid=(low+high)/2;
                    if(v[mid].first[0]>=tgt)high=mid-1;
                    else low=mid+1;
                }
                if(low<=n-1 && v[low].first[0]>=tgt) ans[v[i].second]=v[low].second;
        
        }
        return ans;
        
    }
};