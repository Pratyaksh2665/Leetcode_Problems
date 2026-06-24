/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool found(TreeNode* root,TreeNode* target)
    {
        if(!root) return false;

        if(root == target) return true;

        return found(root->left,target) || found(root->right,target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(!root) return NULL;

        if(root == p || root==q) return root;
        
              
        if(found(root->left,p) && found(root->right,q)) return root;
        else if(found(root->left,q) && found(root->right,p)) return root;
        else
        {
            TreeNode* left=lowestCommonAncestor(root->left,p,q);
            TreeNode* right=lowestCommonAncestor(root->right,p,q);
            if(left) return left;
            return right;
            
        }


        return NULL;

    }
};