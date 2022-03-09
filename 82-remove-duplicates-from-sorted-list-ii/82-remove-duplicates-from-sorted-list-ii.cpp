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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *t=new ListNode(0);
        t->next=head;
        
        while(t->next && t->next->next)
        {
            if(t->next->val==t->next->next->val)
            {
                ListNode *t1=t->next;
                int x=t1->val;
                while(t1 && t1->val==x)
                    t1=t1->next;
                
                if(head==t->next)
                    head=t1;
                
                t->next=t1;
            }
            else
                t=t->next;
        }
        
        return head;
    }
};