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
    int maxm=0;
    set<int>s;
    unordered_map<TreeNode* , TreeNode*>mp;
    void trav(TreeNode* root)
    {
        if(!root) return;

        if(root->left) mp[root->left]=root;
        if(root->right) mp[root->right]=root;

        trav(root->left);
        trav(root->right);

        return;
    }
    TreeNode* find(TreeNode* root,int start)
    {
        if(!root) return nullptr;
        if(root->val == start) return root;

        TreeNode* left = find(root->left , start);
        if(left) return left;
        
        return find(root->right , start);

        
    }
    void check(TreeNode* root ,int lvl )
    {
        if(!root) return;
        if(s.count(root->val)) return;
        s.insert(root->val);
        maxm=max(maxm,lvl);
        check(root->left , lvl+1);
        check(root->right , lvl+1);
        if(mp.count(root)>0) check(mp[root] , lvl+1);

        return;
    }
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;

        trav(root);
        TreeNode* node = find(root , start);
        int lvl=0;
        check(node , lvl);

        return maxm;
    }
};