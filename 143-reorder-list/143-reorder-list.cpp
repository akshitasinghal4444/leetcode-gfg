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
    ListNode* reverse(ListNode* h)
    {
        if(!h || !h->next)
            return h;
        
        ListNode *curr,*p,*n;
        p=NULL;
        curr=h;
        
        while(curr)
        {
            n=curr->next;
            curr->next=p;
            p=curr;
            curr=n;            
        }
        
        return p;
    }
    
    void reorderList(ListNode* head)
    {
        if(!head)
            return;
        
        ListNode *t1,*t2;
        t1=t2=head;
        
        while(t2->next && t2->next->next)
        {
            t1=t1->next;
            t2=t2->next->next;
        }
        
        t2=t1->next;
        t1->next=NULL;
        
        t2=reverse(t2);
        
        while(head && t2)
        {
            t1=head->next;
            head->next=t2;
            t2=t2->next;
            head->next->next=t1;
            head=t1;
        }
    }
    
    /*
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        
        ListNode *s,*f;
        s=f=head;
        while(f->next && f->next->next)
        {
            s=s->next;
            f=f->next->next;
        }
        
        
        f=s->next;
        s->next=NULL;
        s=f;
        f=f->next;
        s->next=NULL;
        ListNode* t;
        
        while(f)
        {
            t=f->next;
            f->next=s;
            s=f;
            f=t;
        }
        
        f=head;
        t=f;

        while(s)
        {
            t=t->next;
            f->next=s;
            s=s->next;
            f->next->next=t;
            f=t;
            
        }
    }
    */
};