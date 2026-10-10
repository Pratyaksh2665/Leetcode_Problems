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
    int maxm = 0;
    int count(TreeNode* root)
    {
        if(!root) return 0;
        int left = count(root->left);
        int right = count(root->right);
        int l=0;
        int r = 0;
        if(root->left && root->left->val == root->val)
        {
            l = left + 1;
        }

        if(root->right && root->right->val == root->val)
        {
            r = right + 1;
        }
        maxm = max(maxm,l+r);
        
        return max(l,r);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;

        count(root);

        return maxm;
    }
};