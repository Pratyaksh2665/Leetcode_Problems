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
TreeNode* build(vector<int>& v, int l, int r)
{
    if(l > r) return NULL;

    int mid = (l + r) / 2;

    TreeNode* root = new TreeNode(v[mid]);

    root->left = build(v, l, mid - 1);
    root->right = build(v, mid + 1, r);

    return root;
}
    void trav(TreeNode* root,vector<int>&v)
    {
        if(!root) return ;

        trav(root->left,v);
        v.push_back(root->val);
        trav(root->right,v);
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return NULL;

        vector<int>v;
        trav(root,v);

        return build(v, 0, v.size() - 1);
    }
};