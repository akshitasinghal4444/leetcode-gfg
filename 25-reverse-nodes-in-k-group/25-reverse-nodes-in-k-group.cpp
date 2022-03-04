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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if(!head || !head->next)
            return head;
        
        ListNode *t=head,*p=NULL,*n;
        int i=0;
        
        while(t && i++<k)
            t=t->next;
        
        if(i<k)
            return head;
        
        t=head;
        i=0;
        while(t && i<k)
        {
            n=t->next;
            t->next=p;
            
            p=t;
            t=n;
            
            i++;
        }
        
        head->next=reverseKGroup(t,k);
        
        return p;
    }
    
    /*
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *t1,*t2,*p,*n;
        int i;
        
        t1=t2=head;
        for(i=0;i<k;i++)
        {
            if(!t1)
                return head;
            t1=t1->next;
        }
        p=NULL;
        
        while(t1!=t2)
        {
            n=t2->next;
            t2->next=p;
            p=t2;
            t2=n;
        }
        head->next=reverseKGroup(t1,k);
        return p;
    }
    */
};