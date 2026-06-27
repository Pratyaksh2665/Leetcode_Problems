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
    unordered_map<TreeNode* ,int>mp;
    int levels(TreeNode* root)
    {
        if(!root) return 0;

        return 1+max(levels(root->left),levels(root->right));
    }
    void leave(TreeNode* root ,int lvl)
    {
        if(!root) return;

        mp[root]=lvl;

        leave(root->left , lvl+1);
        leave(root->right , lvl+1);
       
    }
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;

        int x=levels(root);
        leave(root,0);
        int sum=0;
        for(auto it:mp)
        {
            if(it.second==x-1) sum+=it.first->val;
        }
        
        return sum;
    }
};