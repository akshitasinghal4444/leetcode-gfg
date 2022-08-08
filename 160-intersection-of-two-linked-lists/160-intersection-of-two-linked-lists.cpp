/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int len(ListNode *h)
    {
        int l=0;
        
        while(h)
        {
            l++;
            h=h->next;
        }
        
        return l;
    }
    
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) 
    {
        int l1=len(h1),l2=len(h2),diff=abs(l1-l2);
        
        if(l1>l2)
        {
            while(diff--)
                h1=h1->next;
        }
        else
        {
            while(diff--)
                h2=h2->next;
        }
        
        while(h1)
        {
            if(h1==h2)
                return h1;
            
            h1=h1->next;
            h2=h2->next;
        }
        
        return h1;
    }
    
    /*
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = !a ? headB : a->next;
            b = !b ? headA : b->next;
        }
        return a;
    }
    */
};