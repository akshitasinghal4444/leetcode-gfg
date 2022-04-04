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
    
    ListNode* swapNodes(ListNode* head, int k)
    {
        ListNode *t,*t1,*t2;
        t=head;
        
        while(--k)
            t=t->next;
        
        t1=t;
        t2=head;
        
        while(t->next)
        {
            t=t->next;
            t2=t2->next;
        }
        
        int x=t1->val;
        t1->val=t2->val;
        t2->val=x;
        
        return head;
    }
    
    /*
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* t=head,*t1,*t2;
        
        int n=0;
        while(t)
        {
            t=t->next;
            n++;
        }
        
        t=head;
        if(k==1 || k==n)
        {
            if(!t->next)
                return head;
            
            while(t->next->next)
                t=t->next;
            
            t1=t->next;
            t->next=head;
            t1->next=head->next;
            head->next=NULL;
            return t1;
        }
        
        for(int i=1;i<k-1;i++)
            t=t->next;
        
        t1=t;
        t2=head;
        t=t->next->next;
        while(t->next)
        {
            t=t->next;
            t2=t2->next;
        }
        
        t=t1->next;
        t1->next=t2->next;
        t2->next=t;
        
        t=t1->next->next;
        t1->next->next=t2->next->next;
        t2->next->next=t;
        
        return head;
    }
    */
};