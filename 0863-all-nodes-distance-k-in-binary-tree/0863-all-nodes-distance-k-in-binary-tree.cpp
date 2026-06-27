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
vector<int>ans;
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
    void check(TreeNode* root ,int lvl ,int k)
    {
        if(!root) return;
        if(s.count(root->val)) return;
        s.insert(root->val);
        if(lvl == k) ans.push_back(root->val);
        check(root->left , lvl+1 ,k);
        check(root->right , lvl+1 ,k);
        if(mp.count(root)>0) check(mp[root] , lvl+1 , k);

        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};

        trav(root);
       
        int lvl=0;
        check(target , lvl ,k);

        return ans;
    }
};