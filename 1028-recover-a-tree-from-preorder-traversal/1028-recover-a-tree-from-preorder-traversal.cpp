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
    int idx=0;
    TreeNode* dfs(string s,int expectedDepth)
    {
        if(idx >= s.length()) return NULL;
        int count=0;
        int temp=idx;
        while(idx < s.size() && s[idx]=='-')
        {
            idx++;
            count++;
        }
        
        if(count!=expectedDepth) {
            idx=temp;
            return NULL;
        }
        string str="";
        while(idx < s.size() && s[idx]!='-')
        {
            str+=s[idx];
            idx++;
        } 
        TreeNode* node = new TreeNode(stoi(str));
        
        
        node->left = dfs(s,count+1);
        node->right=dfs(s,count+1);

        return node;

    }
    TreeNode* recoverFromPreorder(string traversal) {
        int n=traversal.length();

        return dfs(traversal,0);

    }
};