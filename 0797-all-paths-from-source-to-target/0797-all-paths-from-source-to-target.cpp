class Solution {
public:
    vector<vector<int>>ans;
    void dfs(vector<vector<int>>& graph,int node,vector<int>&v)
    {
        v.push_back(node);
        if(node == graph.size()-1)
        {
            ans.push_back(v);
            v.pop_back();
            return;
        }

        for(auto it:graph[node])
        {
            dfs(graph,it,v);

        }
        v.pop_back();

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>v;
        dfs(graph , 0 ,v);

        return ans;
    }
};