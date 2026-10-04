class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v,w});
        }
        vector<vector<int>>dis(k+2,vector<int>(n,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq; //  stops , node , distance
        pq.push({0,{src , 0}});
        dis[0][src]=0;
        int minm = 1e9;
        while(pq.size()>0)
        {
            int stop = pq.top().first;
            int node = pq.top().second.first;
            int ds = pq.top().second.second;

            pq.pop();
            if(node == dst)
            {
                minm = min(minm , ds);
            }

            if(stop == k+1)
                continue;

            for(auto it:adj[node])
            {
                int nw = it.first;
                if(ds + it.second < dis[stop+1][nw])
                {
                    dis[stop+1][nw] = ds + it.second;
                    pq.push({stop+1,{nw,dis[stop+1][nw]}});
                }
            }
        }
        if(minm==1e9) return -1;
        return minm;
    }
};