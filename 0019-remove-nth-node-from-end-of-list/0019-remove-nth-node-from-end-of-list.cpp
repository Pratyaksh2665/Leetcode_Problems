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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int cnt=0;
        while(temp)
        {
            cnt++;
            temp=temp->next;
        }
        
        if(n==cnt)
        {
            return head->next;
        }
        cnt=cnt-n;

        temp=head;
        while(temp && cnt-1)
        {
            cnt--;
            temp=temp->next;
        }
        if(temp->next) temp->next=temp->next->next;
        else temp->next=nullptr;

        return head;
    }
};