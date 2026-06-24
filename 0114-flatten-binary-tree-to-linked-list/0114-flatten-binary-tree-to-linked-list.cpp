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
    TreeNode* dummy=new TreeNode(1000);
    TreeNode* temp=dummy;
    void flatten(TreeNode* root) {
       if(!root) return;

        TreeNode* node=root;
        TreeNode* lft=root->left;
        TreeNode* rt=root->right;

        temp->left=NULL;
        temp->right=node;
        temp=temp->right;

        flatten(lft);
        flatten(rt);

        temp->right=NULL;
        temp->left=NULL;

        dummy=dummy->right;

        return;

    }
};