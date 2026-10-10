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
    TreeNode* construct(vector<int>& pre, vector<int>& in,int st1 , int ei1 , int st2 , int ei2)
    {
        if(st1>ei1 || st2>ei2) return NULL;
        TreeNode* node = new TreeNode(pre[st1]);
        int idx = -1;
        for(int i=st2;i<=ei2;i++)
        {
            if(pre[st1]==in[i])
            {
                idx = i;
                break;
            }
        }
        if(idx == -1) return NULL;
        int len = idx-st2;// itni length ka left rhega preorder me bhi na
        node->left = construct(pre,in,st1+1,st1+len,st2,idx-1);
        node->right = construct(pre , in , st1+len+1 ,ei1 , idx+1,ei2);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return construct(preorder , inorder ,  0 , n-1 , 0,n-1);
    }
};