class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {

        vector<vector<long long>> dis(n, vector<long long>(n, LLONG_MAX));

        for (auto &e : edges) {
            dis[e[0]][e[1]] = e[2];
            dis[e[1]][e[0]] = e[2];
        }

        for (int i = 0; i < n; i++)
            dis[i][i] = 0;

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    if (dis[i][k] == LLONG_MAX || dis[k][j] == LLONG_MAX)
                        continue;

                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        int minCount = INT_MAX;
        int cityNo = -1;

        for (int city = 0; city < n; city++) {
            int count = 0;
            for (int adj = 0; adj < n; adj++) {
                if (city != adj && dis[city][adj] <= dt)
                    count++;
            }
            if (count <= minCount) {
                minCount = count;
                cityNo = city;  
            }
        }

        return cityNo;
    }
};