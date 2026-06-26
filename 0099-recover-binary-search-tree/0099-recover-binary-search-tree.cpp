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
    void traverse(TreeNode* root,vector<int>&v)
    {
        if(!root) return;
        
        traverse(root->left,v);
        v.push_back(root->val);//inorder le through check kr lenge ki kya dikkat h 
        traverse(root->right,v);
    }
    void find(TreeNode* root,int x,int y)
    {
        if(!root) return;

        if(root->val==x)
            root->val=y;
        else if(root->val==y)
            root->val=x;

        find(root->left,x,y);
        find(root->right,x,y);
    }
    
    void recoverTree(TreeNode* root) {
        vector<int>v;
        traverse(root,v);
        vector<int>s=v;
        sort(s.begin(),s.end());
        int n=v.size();
        vector<int>t;
        int i=0;
        int j=0;
        while(i<n && j<n)
        {
            if(v[i]!=s[j]) t.push_back(v[i]);
            i++;
            j++;

        }
        int x=t[0];
        int y=t[1];

        find(root,x,y);
        return;
    }
};