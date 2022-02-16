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
    ListNode* swapPairs(ListNode* head)
    {
        if(!head || !head->next)
            return head;
        
        ListNode *t=head->next;
        head->next=swapPairs(t->next);
        t->next=head;
        
        return t;
    }
    
    /*
    ListNode* swapPairs(ListNode* head) {
        ListNode* t1=head,*t2,*t3;
        
        if(head && head->next)
        head=head->next;
        
        while(t1 && t1->next)
        {
            t2=t1->next;
            
            if(t2->next && t2->next->next)
                t1->next=t2->next->next;
            else
                t1->next=t2->next;
            
            t3=t2->next;
            t2->next=t1;
            
            t1=t3;
        }
        
        return head;
    }
    */
};