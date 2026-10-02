class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();

        int r[4]={-1,1,0,0};
        int c[4]={0,0,-1,1};

        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;

        pq.push({0,{0,0}});

        vector<vector<int>>vis(m,vector<int>(n,0));

        while(pq.size()>0)
        {
            int d = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;

            pq.pop();

            if(vis[i][j]) continue;

            vis[i][j]=1;

            if(i==m-1 && j==n-1)
            {
                return d;
            }

            for(int k=0;k<4;k++)
            {
                int nr = i+r[k];
                int nc = j+c[k];

                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc])
                {
                    int dis = abs(heights[i][j]-heights[nr][nc]);

                    int maxm = max(d,dis);

                    pq.push({maxm,{nr,nc}});
                }
            }
        }

        return 0;
    }
};