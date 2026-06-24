/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool flag = false;
    void find(TreeNode* root, int tgt) {
        if (!root)
            return;

        tgt -= root->val;    
        
        if (tgt == 0 && !root->left && !root->right) {
            flag = true;
            return;
        }

        

        find(root->left, tgt);
        find(root->right, tgt);

        tgt += root->val;

        return;
    }
    bool hasPathSum(TreeNode* root, int tgt) {
        find(root, tgt);
        return flag;
    }
};