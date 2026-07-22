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
    int helper(TreeNode* root,bool flag,unordered_map<TreeNode*, vector<int>> &dp)
    {
        if(!root)return -1;
        if(dp.find(root) != dp.end() && dp[root][flag] != -1)return dp[root][flag];

        if(dp.find(root) == dp.end())dp[root] = {-1, -1};//initialization

        int len;
        if(flag)
        {
            len=1+helper(root->left,!flag,dp);
        }
        else
        {
            len=1+helper(root->right,!flag,dp);
        }
        maxm=max(maxm,len);
        helper(root->left, true, dp);
        helper(root->right, false, dp);
        return dp[root][flag] = len;
    }
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;
        unordered_map<TreeNode*, vector<int>> dp;
        helper(root,true,dp);
        helper(root,false,dp);
        
        return maxm;
    }
};