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
    vector<string> v;
    void res(TreeNode* root, string& s) {
        if (!root)
            return;

        s += ('a' + root->val);

        if (!root->left && !root->right) {
            string temp = s;
            reverse(temp.begin(), temp.end());
            v.push_back(temp);

            s.pop_back();
            return;
        }

        res(root->left, s);
        res(root->right, s);

        s.pop_back();
    }

    string smallestFromLeaf(TreeNode* root) {
        if (!root)
            return "";
        string s = "";
        res(root, s);

        sort(v.begin(), v.end());

        return v[0];
    }
};