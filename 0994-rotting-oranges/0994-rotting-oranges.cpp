class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int fresh=0;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) fresh++;
                if(grid[i][j]==2)q.push({{i,j},0});
            }
        }
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        int time=0;
        while(q.size()>0)
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t=q.front().second;
            q.pop();

            time=max(time,t);
            for(int i=0;i<4;i++)
            {
                int nr  = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1)
                {
                    fresh--;
                    grid[nr][nc]=2;
                    q.push({{nr,nc},t+1});
                }
            }
        }

        if(fresh!=0) return -1;

        return time;
    }
};