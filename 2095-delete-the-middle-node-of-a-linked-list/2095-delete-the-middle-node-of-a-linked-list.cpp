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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(!head || !head->next)
            return NULL;
        
        ListNode *s,*f,*p;
        s=f=head;
        
        while(f && f->next)
        {
            p=s;
            s=s->next;
            f=f->next->next;
        }
        
        p->next=p->next->next;
        
        return head;
    }
};