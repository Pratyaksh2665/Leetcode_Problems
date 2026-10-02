class Solution {
public:
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {

        int m = mat.size();
        int n = mat[0].size();

        if(mat[src[0]][src[1]] == 1 || mat[dest[0]][dest[1]] == 1)
            return -1;

        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<pair<pair<int,int>,int>> q;

        q.push({{src[0], src[1]}, 1});
        vis[src[0]][src[1]] = 1;

        int row[8] = {-1,-1,-1,0,0,1,1,1};
        int col[8] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;

            q.pop();

            if(r == dest[0] && c == dest[1])
                return dist;

            for(int k=0;k<8;k++)
            {
                int nr = r + row[k];
                int nc = c + col[k];

                if(nr>=0 && nr<m && nc>=0 && nc<n &&
                   !vis[nr][nc] && mat[nr][nc]==0)
                {
                    vis[nr][nc] = 1;

                    q.push({{nr,nc},dist+1});
                }
            }
        }

        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<int> src = {0,0};
        vector<int> dest = {m-1,n-1};

        return shortestPath(grid,src,dest);
    }
};