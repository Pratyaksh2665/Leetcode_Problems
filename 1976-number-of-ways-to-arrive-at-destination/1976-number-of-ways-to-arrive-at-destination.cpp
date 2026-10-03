class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto it:roads)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        >pq;

        vector<long long>dis(n,1e18);
        vector<int>ways(n,0);

        dis[0]=0;
        ways[0]=1;

        pq.push({0,0});

        int mod = 1e9+7;

        while(pq.size()>0)
        {
            long long dst = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if(dst > dis[node])
                continue;

            for(auto it:adj[node])
            {
                int nw = it.first;
                int wt = it.second;

                if(dst + wt < dis[nw])
                {
                    dis[nw] = dst + wt;
                    ways[nw] = ways[node];

                    pq.push({dis[nw],nw});
                }
                else if(dst + wt == dis[nw])
                {
                    ways[nw] = (ways[nw] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1];
    }
};