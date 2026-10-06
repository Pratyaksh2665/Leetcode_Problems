class Solution { 
public: 
    map<TreeNode*,TreeNode*>mp; // node, parent
    map<TreeNode*,bool>vis;
    int maxm = 0;

    void trav(TreeNode* root) 
    { 
        if(!root) return; 

        if(root->left) mp[root->left] = root; 
        if(root->right) mp[root->right] = root; 

        trav(root->left); 
        trav(root->right); 
    } 

    TreeNode* found(TreeNode* root,int start) 
    { 
        if(!root) return NULL; 

        if(root->val == start) 
            return root;

        TreeNode* left = found(root->left,start); 

        if(left) return left;

        return found(root->right,start); 
    } 

    void timess(TreeNode* root, int time) 
    { 
        if(!root || vis[root]) return;

        vis[root] = true;

        maxm = max(maxm,time);

        if(root->left) 
            timess(root->left,time+1); 
         
        if(root->right) 
            timess(root->right,time+1); 

        if(mp.count(root)!=0) 
            timess(mp[root],time+1); 
    } 

    int amountOfTime(TreeNode* root, int start) { 
        trav(root);

        TreeNode* node = found(root,start); 

        timess(node,0); 

        return maxm; 
    } 
};