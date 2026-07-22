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
    vector<TreeNode*>helper(vector<int>&v,int start,int end)
    {
        vector<TreeNode*>ans;
        if( start>end)
        {   
            ans.push_back(NULL);
            return ans;
            
        }
        for(int i=start;i<=end;i++)
        {
            
            vector<TreeNode*>lefttrees=helper(v,start,i-1);// left wale small 
            vector<TreeNode*>righttrees=helper(v,i+1,end);// right wale large
            for(int j=0;j<lefttrees.size();j++)
            {
                
                for(int k=0;k<righttrees.size();k++)
                {
                    TreeNode* node=new TreeNode(v[i]);
                    node->left=lefttrees[j];
                    node->right=righttrees[k];
                    ans.push_back(node);
                }
            }
        }

        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        vector<int>v;
        for(int i=0;i<n;i++)v.push_back(i+1);
       
        return helper(v,0,n-1);
    }
};