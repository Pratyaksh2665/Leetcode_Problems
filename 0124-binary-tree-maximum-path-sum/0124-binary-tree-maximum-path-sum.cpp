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
    int maxm=INT_MIN;
    int  sum(TreeNode* root)
    {
        if(!root) return 0;

        int leftsum=max(0,sum(root->left));
        int rightsum=max(0,sum(root->right));

        maxm=max(maxm , root->val+leftsum+rightsum);

        return root->val+max(leftsum,rightsum);
    }
    void helper(TreeNode* root)
    {
        if(!root) return;

        int p=sum(root);
        maxm=max(maxm,p);
        helper(root->left);
        helper(root->right);

        return;

    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        helper(root);
        return maxm;
        
    }
};