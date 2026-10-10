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
    TreeNode* rnew(vector<int>&nums , int si , int ei)
    {
        if(si>ei || si<0 ) return NULL;
        int mid = (si+ei)/2;

        TreeNode* node = new TreeNode(nums[mid]);
        node->left = rnew(nums , si , mid-1);
        node->right = rnew(nums , mid+1 , ei);

        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int si = 0;
        int ei = n-1;
        return rnew(nums, si , ei);
    }
};