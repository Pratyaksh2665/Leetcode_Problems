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
    int maxm = INT_MIN;
    int idx = -1;
    int levels(TreeNode* root)
    {
        if(!root) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }

    void nthLevel(TreeNode* root , int l , int &sum)
    {
        if(!root) return;
        if(l==0)
        {
            sum+=root->val;
        }
        nthLevel(root->left ,l-1, sum);
        nthLevel(root->right ,l-1 , sum);
        
        return;
    }

    void total(TreeNode* root)
    {
        int total_levels = levels(root);

        for(int i=0;i<total_levels;i++)
        {
            int sum = 0;
            nthLevel(root,i,sum);
            if(sum > maxm)
            {
                maxm = sum;
                idx = i+1;
            }
        }

        return;
    }
    
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        total(root);
        return idx;
    }
};