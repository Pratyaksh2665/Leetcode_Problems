/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        int n=des.size();
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>c;// for child
        unordered_set<int>p;//for parent
        TreeNode* ans;
        for(auto it:des)
        {
           int u=it[0];
           int v=it[1];
           int w=it[2];

            if(mp.find(u)==mp.end())
            {
                mp[u]=new TreeNode(u);
            }
            if(mp.find(v)==mp.end())
            {
                mp[v]=new TreeNode(v);
            }

            TreeNode* par=mp[u];
            TreeNode* ch=mp[v];

            if(w)
            {
                par->left=ch;
            }
            else par->right=ch;

            c.insert(v);
            p.insert(u);
        }

        for(auto it:p)
        {
            if(c.count(it)==0) {
                return mp[it];
                break;
            }
        }

        return nullptr;
    }
};