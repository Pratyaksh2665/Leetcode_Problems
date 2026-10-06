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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        deque<pair<TreeNode*,int>>dq;
        long long maxm = LLONG_MIN;
        dq.push_back({root,0});
        while(dq.size()>0)
        {
            long long size=dq.size();
            long long startidx=dq.front().second;
            long long endidx=dq.back().second;

            maxm=max(maxm,endidx-startidx+1);

            for(long long i=0;i<size;i++)
            {
                TreeNode* front = dq.front().first;
                long long index = dq.front().second;
                dq.pop_front();
                if(front->left) dq.push_back({front->left,2*index+1});
                if(front->right) dq.push_back({front->right,2*index+2});
            }
        }

        return maxm;
    }
};