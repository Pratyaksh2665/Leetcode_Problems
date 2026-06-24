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
    unordered_map<TreeNode*,TreeNode*>mp;//node parent
    void parent(TreeNode* root)
    {
        if(!root) return;
        if(root->left) mp[root->left]=root;
        if(root->right) mp[root->right] = root;

        parent(root->left);
        parent(root->right);
        return;
        
    }
    int sumEvenGrandparent(TreeNode* root) {
        if(!root) return 0;
        parent(root);
        int sum=0;
        for(auto it:mp)
        {
            TreeNode* par=it.second;
            if(mp.count(par)>0 && (mp[par]->val)%2 == 0) 
            {
                sum+=it.first->val;
            } 
        }
        return sum;
    }
};