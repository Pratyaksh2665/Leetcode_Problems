class Solution { 
public: 
    vector<string>ans; 

    void helper(TreeNode* root, string &s) 
    { 
        if(!root) return; 

        int len = s.length();

        s += to_string(root->val) + "->"; 

        // leaf node
        if(!root->left && !root->right)
        {
            s.pop_back(); // remove last '>'
            s.pop_back(); // remove last '-'
            ans.push_back(s);
            s.erase(len); // backtrack
            return;
        }

        helper(root->left, s); 
        helper(root->right, s); 

        // backtrack to the state before this node
        s.erase(len);
    } 

    vector<string> binaryTreePaths(TreeNode* root) { 
        string s = ""; 
        helper(root, s); 
        return ans; 
    } 
};