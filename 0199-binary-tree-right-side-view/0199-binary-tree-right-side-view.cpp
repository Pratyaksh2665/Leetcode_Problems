// class Solution {
// public:
//     vector<int> v;
//     void helper(TreeNode* root, int level)
//     {
//         if(!root) return;

//         if(level == v.size())
//             v.push_back(root->val);

//         helper(root->right, level+1);
//         helper(root->left, level+1);
//     }
//     vector<int> rightSideView(TreeNode* root) {
//         helper(root, 0);
//         return v;
//     }
// };
class Solution {
public:

    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        map<int,TreeNode*>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(q.size()>0)
        {
            TreeNode* front = q.front().first;
            int hd =  q.front().second.first;
            int level = q.front().second.second;
            q.pop();

            mp[level]=front;

            if(front->left) q.push({front->left,{hd-1,level+1}});
            if(front->right) q.push({front->right,{hd+1,level+1}});
        }

        for(auto it:mp)
        {
            TreeNode* x = it.second;
            ans.push_back(x->val);
        }

        return ans;
    }
};