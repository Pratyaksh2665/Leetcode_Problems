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
    int level(TreeNode* root)
    {
        if(!root) return 0;
        return 1+max(level(root->left),level(root->right));
    }
    void nthlevel(TreeNode* root,vector<int>&res,int n,int count)
    {
        if(!root) return;
        if(count==n) 
        {
            res.push_back(root->val);
        }
        count++;
        nthlevel(root->left,res,n,count);
        nthlevel(root->right,res,n,count);
    }
    void numbers(TreeNode* root,vector<vector<int>>&ans)
    {
        if(!root) return;
        int x=level(root);
        for(int i=0;i<x;i++)
        {
            vector<int>v;
            nthlevel(root,v,i,0);
            if(i%2!=0) 
            {
                reverse(v.begin(),v.end());
                ans.push_back(v);
            } 
            else ans.push_back(v);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        numbers(root,ans);
        return ans;

        
    }
};