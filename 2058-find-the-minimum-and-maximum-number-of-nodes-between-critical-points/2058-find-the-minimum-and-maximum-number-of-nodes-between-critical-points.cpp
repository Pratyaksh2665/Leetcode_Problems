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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans;
        ListNode* curr=head->next;
        ListNode* pre=head;
        int size=1;
        while(curr->next)
        {
            size++;
            if(((curr->val > pre->val)&&(curr->val > curr->next->val))||((curr->val < pre->val)&&(curr->val < curr->next->val)))
            {
                ans.push_back(size);
               
            }
            curr=curr->next;
            pre=pre->next;
        }

        if(ans.size()<2)return {-1,-1};
        int mn = INT_MAX;

        for(int i=1;i<ans.size();i++)mn = min(mn, ans[i]-ans[i-1]);
        int mx = ans.back() - ans.front();
        
        
        return {mn, mx};
        
        
    }
};