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
        ListNode* res=new ListNode(100);
        ListNode* c=res;
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
        return res->next;
    };
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* a=head;
        ListNode* b=slow->next;
        slow->next=NULL;
        
        a=sortList(a);
        b=sortList(b);
        ListNode* ans=merge(a,b);

        return ans;
        
    }
};