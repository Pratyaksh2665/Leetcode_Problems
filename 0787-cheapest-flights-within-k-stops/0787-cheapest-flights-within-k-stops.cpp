class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];

            adj[u].push_back({v,w});

        }
        vector<int>dis(n,1e9);

        queue<pair<int,pair<int,int>>>q;  // stops , node , distance
        q.push({0,{src,0}});
        while(q.size()>0)
        {
            int stop=q.front().first;
            int node=q.front().second.first;
            int ds=q.front().second.second;
            // if(node==dst) return dis[node];
            q.pop();
            if(stop >= k+1) continue;
            
            for(auto it:adj[node])
            {
                if(ds + it.second < dis[it.first])
                {
                    dis[it.first]=ds+it.second;
                    q.push({stop+1,{it.first,dis[it.first]}});
                }
            }
        }

       return dis[dst] == 1e9 ? -1 : dis[dst];


    }
};