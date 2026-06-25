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
    TreeNode* helper(vector<int>& pre, vector<int>& post,int i,int ei,int j,int ej)
    {
        if(i>ei || j>ej) return NULL;
        TreeNode* node = new TreeNode(pre[i]);
        if(i==ei) return node;
        
        int tgt=pre[i+1];
        int idx=j;
        while(idx<=ej)
        {
            if(post[idx]==tgt) break;
            idx++;
        }
        int left=idx-j+1;
        int right=ej-idx;

        node->left=helper(pre,post,i+1,i+left,j,idx);
        node->right=helper(pre,post,i+left+1,ei,idx+1,ej-1);

        return node;

    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n=pre.size();

        return helper(pre,post,0,n-1,0,n-1);
        
    }
};