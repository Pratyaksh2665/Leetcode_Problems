/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q; // node , hd,level
        vector<vector<int>> ans;

        if (!root)
            return ans;
        q.push({root, {0, 0}});

        while (q.size() > 0) {
            pair<TreeNode*, pair<int, int>> temp = q.front();

            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;

            q.pop();

            nodes[hd][level].push_back(frontNode->val);

            if (frontNode->left)
                q.push({frontNode->left, {hd - 1, level + 1}});
            if (frontNode->right)
                q.push({frontNode->right, {hd + 1, level + 1}});
        }

        for (auto it : nodes) {
            vector<int> col;

            for (auto j : it.second) {
                sort(j.second.begin(), j.second.end());

                for (auto k : j.second) {
                    col.push_back(k);
                }
            }

            ans.push_back(col);
        }
        return ans;
    }
};