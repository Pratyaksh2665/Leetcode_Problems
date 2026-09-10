class Solution {
public:
    int ans = 0;

    // helper returns subtree sum in 'sum' and subtree node count in 'x' (by reference)
    int sum(TreeNode* root,int &count)
    {
        if(!root) return 0;
        count++;
        int leftsum=sum(root->left,count);
        int rightsum=sum(root->right,count);
        return root->val+leftsum+rightsum;

    }
    void solve(TreeNode* root)
    {
        if(root==NULL) return;
        int count=0;
        int avg=sum(root,count)/count;
        if(avg==root->val) ans++;
        solve(root->left);
        solve(root->right);
    }


    int averageOfSubtree(TreeNode* root) {
       if(root==NULL) return 0;
       solve(root);
       return ans;
    }
};
