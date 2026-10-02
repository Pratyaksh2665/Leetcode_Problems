class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& arr) {
        int m=arr.size();
        int n=arr[0].size();

        vector<vector<int>>dis(m,vector<int>(n,1e9));
        dis[0][0]=0;
        int x[4]={-1,1,0,0};
        int y[4]={0,0,-1,1};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        while(pq.size()>0)
        {
            int wt=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(i==m-1 && j==n-1) break;

            for(int k=0;k<4;k++)
            {
                int nrow=i+x[k];
                int ncol=j+y[k];


                if(nrow >= 0 && nrow<m && ncol >= 0 && ncol < n)
                {
                    int newEffort =max(wt, abs(arr[i][j] - arr[nrow][ncol]));
                            
                    
                    if(newEffort < dis[nrow][ncol])
                    {
                        dis[nrow][ncol] = newEffort;
                        pq.push({newEffort,{nrow,ncol}});
                    }
                    
                }
            }
        }
        return dis[m-1][n-1];
        
    }
};