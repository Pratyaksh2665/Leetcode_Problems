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
    TreeNode* build(vector<int>&post,vector<int>&in,int inlo,int inhi,int postlo,int posthi)
    {
        if(posthi<postlo || inlo>inhi) return NULL;
        TreeNode* root=new TreeNode(post[posthi]);
        
        if(posthi==postlo) return root;
        
        int i=0;
        while(i<=inhi)
        {
            if(post[posthi]==in[i]) break;
            i++;
        }
        int left=i-inlo;
        int right=inhi-i;

        root->left=build(post,in,inlo,i+left-1,postlo,postlo+left-1);
        root->right=build(post,in,i+1,inhi,postlo+left,posthi-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        return build(postorder,inorder,0,n-1,0,n-1);
        
    }
};