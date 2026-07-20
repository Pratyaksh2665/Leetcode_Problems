class Solution {
public:
    bool find(vector<vector<char>>& board, string word,int i,int j,string s,vector<vector<int>>&vis)
    {
        int m=board.size();
        int n=board[0].size();
        if(vis[i][j]) return false;
        vis[i][j]=1;
        
        int nr[4]={-1,1,0,0};
        int nc[4]={0,0,-1,1};
        
        bool flag=false;
        s+=board[i][j];
        if(s.size() > word.size())
        {
            vis[i][j] = 0;
            return false;
        }

        if(s != word.substr(0, s.size()))
        {
            vis[i][j] = 0;
            return false;
        }

        if(s == word)return true;
            
        for(int k=0;k<4;k++)
        {
            int row=nr[k]+i;
            int col=nc[k]+j;

            if(row>=0 && row<m && col>=0 && col<n && !vis[row][col])
            {
                flag=find(board,word,row,col,s,vis);
                if(flag) return true;
            }
        }
        s.pop_back();
        vis[i][j] = 0;
        return flag;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(find(board, word, i, j, "", vis))
                    return true;
            }
        }
        return false;
    }
};