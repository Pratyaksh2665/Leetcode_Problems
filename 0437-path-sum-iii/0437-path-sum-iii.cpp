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
    int count=0;
    void sum(TreeNode* root,int tgt,long long &add)
    {
        if(!root) return;
        add+=root->val;
        if(add==tgt) count++;
        sum(root->left,tgt,add);
        sum(root->right,tgt,add);
        add-=root->val;

        return;
    }
    void helper(TreeNode* root,int &tgt)
    {
        if(!root) return;
        long long add=0;
        sum(root,tgt,add);

        helper(root->left,tgt);
        helper(root->right,tgt);

        return;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        helper(root,targetSum);

        return count;
    }
};