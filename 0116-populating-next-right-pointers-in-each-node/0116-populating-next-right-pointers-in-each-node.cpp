// /*
// // Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;
//     Node* next;

//     Node() : val(0), left(NULL), right(NULL), next(NULL) {}

//     Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

//     Node(int _val, Node* _left, Node* _right, Node* _next)
//         : val(_val), left(_left), right(_right), next(_next) {}
// };
// */

// class Solution {
// public:
//     int levels(Node* root)
//     {
//         if(root==NULL) return 0;
//         return 1+max(levels(root->left),levels(root->right));
//     }
//     void levelorder(Node* root,int level,int target,Node* &prev)
//     {
//         if(root==NULL) return;
        
//         if(level==target)
//         {
//             if(prev) prev->next=root;
//             prev=root;
//             return;
            
//         }
//         level++;
//         levelorder(root->left,level,target,prev);
//         levelorder(root->right,level,target,prev);
//         return;
//     }
//     void nthlevels(Node* root)
//     {
//         int n=levels(root);
//         for(int i=1;i<=n;i++)
//         {
//             Node* prev=NULL;
//             levelorder(root,1,i,prev);
            
//         }
//         return;
        
//     }
//     Node* connect(Node* root) {
//         if(root==NULL) return NULL;
//         nthlevels(root);
//         return root;
        
//     }
// };
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(!root) return NULL;
        Node* prev = NULL;
        queue<Node*>q;
        q.push(root);
        while(q.size()>0)
        {
            int size = q.size();
            
            for(int i=0;i<size;i++)
            {
                Node* node = q.front();
                if(prev) prev->next = node;
                prev = node;
                if(i==size-1) 
                {
                    node->next = nullptr;
                    prev = nullptr;
                }
                q.pop(); 

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
        }
        
        return root;
    }
};