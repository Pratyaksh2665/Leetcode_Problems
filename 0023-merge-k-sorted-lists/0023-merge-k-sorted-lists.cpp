/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* a,ListNode* b)
    {
        ListNode* ans=new ListNode(100);
        ListNode* c=ans;
        while(a!=NULL && b!=NULL)
        {
            if(a->val<=b->val)
            {
                c->next=a;
                a=a->next;
                c=c->next;
            }
            else 
            {
                c->next=b;
                b=b->next;
                c=c->next;
            }
            
            
        }
        if(a==NULL) c->next=b;
        else c->next=a;
        return ans->next;
    };
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if(arr.size()<1) return NULL;
        if(arr.size()==1) return arr[0];

        while(arr.size()>1)
        {
            ListNode* a=arr[0];
            arr.erase(arr.begin()+0);
            ListNode* b=arr[0];
            arr.erase(arr.begin()+0);
            ListNode* c=merge(a,b);
            arr.push_back(c);

        }
        return arr[0];
        
    }
};