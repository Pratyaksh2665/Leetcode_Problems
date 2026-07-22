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
    void helper(TreeNode* root,int cnt,bool flag)
    {
        if(!root)
        {
            maxm=max(maxm,cnt);
            cnt=0;
            return;
        }
        if(flag) helper(root->left,cnt+1,!flag);
        else helper(root->right,cnt+1,!flag);
        return;
    }
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        helper(root,0,true);
        helper(root,0,false);
        longestZigZag(root->left);
        longestZigZag(root->right);
        return maxm-1;
    }
};