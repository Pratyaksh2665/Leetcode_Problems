class Solution {
public:
    TreeNode* find(vector<int>& pre, vector<int>& in, int i, int ei, int j, int ej)
    {
        if(i > ei || j > ej) return NULL;

        TreeNode* node = new TreeNode(pre[i]);

        int idx = j;
        while(idx <= ej)
        {
            if(in[idx] == pre[i]) break;
            idx++;
        }

        int leftsize = idx - j;

        node->left = find(pre, in, i + 1, i + leftsize, j, idx - 1);
        node->right = find(pre, in, i + leftsize + 1, ei, idx + 1, ej);

        return node;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();

        return find(pre, in, 0, n - 1, 0, n - 1);
    }
};