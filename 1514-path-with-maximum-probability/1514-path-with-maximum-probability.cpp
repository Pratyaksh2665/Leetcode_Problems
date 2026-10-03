class Solution {
public:
    double maxProbability(int n,
                          vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start_node,
                          int end_node) {

        vector<vector<pair<int,double>>> adj(n);

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];

            adj[u].push_back({v,p});
            adj[v].push_back({u,p});
        }

        vector<double> dis(n,0.0);
        dis[start_node] = 1.0;

        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start_node});

        while(!pq.empty())
        {
            auto [prob,node] = pq.top();
            pq.pop();

            if(node == end_node)
                return prob;

            for(auto it : adj[node])
            {
                int nxt = it.first;
                double edgeProb = it.second;

                double newProb = prob * edgeProb;

                if(newProb > dis[nxt])
                {
                    dis[nxt] = newProb;
                    pq.push({newProb,nxt});
                }
            }
        }

        return 0.0;
    }
};