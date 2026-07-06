class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& inter) {
        int n=inter.size();
       

        vector<vector<int>>ans;
        sort(inter.begin(),inter.end(),[](vector<int>&a,vector<int>&b)
        {
            if(a[0]==b[0]) return a[1]>b[1];

            return a[0]<b[0];
        });

        ans.push_back(inter[0]);
        for(int i=1;i<n;i++)
        {
            int start = inter[i][0];
            int end = inter[i][1];

            int x=ans[ans.size()-1][0];
            int y=ans[ans.size()-1][1];

            if(start >= x && end<=y)
            {
                continue;
            }
            else ans.push_back(inter[i]);
        }

        return ans.size();

    }
};