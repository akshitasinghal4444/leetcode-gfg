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
    bool isPalindrome(ListNode* head)
    {
        ListNode *f,*s,*p,*n;
        p=NULL,s=f=head;
        
        while(f && f->next)
        {
            f=f->next->next;
            n=s->next;
            s->next=p;
            p=s;
            s=n;
        }
        
        if(f)
            s=s->next;
        
        while(s)
        {
            if(p->val!=s->val)
                return 0;
            
            p=p->next;
            s=s->next;
        }
        
        return 1;
    }
    
    /*
    ListNode* reverse(ListNode* h)
    {
        ListNode *p,*c,*n;
        p=NULL,c=h;
        
        while(c)
        {
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        
        return p;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *s,*f;
        s=f=head;
        
        while(f && f->next)
        {
            s=s->next;
            f=f->next->next;
        }
        
        if(f)
        s=s->next;
        
        f=s=reverse(s);
            
        while(f)
        {
            if(head->val!=f->val)
                return 0;
            
            f=f->next;
            head=head->next;
        }
        return 1;
    }
    */
};