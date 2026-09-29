class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int  n= board[0].size();
        vector<vector<char>>ans(m,vector<char>(n,'X'));
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O'){
                q.push({i,0});
                vis[i][0]=1;
            }
        }
        for(int i=0;i<m;i++)
        {
            if(board[i][n-1]=='O')
            {
                q.push({i,n-1});
                vis[i][n-1]=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(board[0][i]=='O')
            {
                q.push({0,i});
                vis[0][i]=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(board[m-1][i]=='O')
            {
                q.push({m-1,i});
                vis[m-1][i]=1;
            }
        }

        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};


        while(q.size()>0)
        {
            int i=q.front().first;
            int j=q.front().second;
            ans[i][j]='O';
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nr=i+dr[k];
                int nc=j+dc[k];

                if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]=='O' && !vis[nr][nc])
                {
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        board=ans;
        return;
    }
};