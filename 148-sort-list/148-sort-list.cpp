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
    ListNode *merge(ListNode *h1,ListNode *h2)
    {
        ListNode *t,*h;
        t=h=new ListNode();
        
        while(h1 && h2)
        {
            if(h1->val<=h2->val)
            {
                t->next=h1;
                h1=h1->next;
            }
            else
            {
                t->next=h2;
                h2=h2->next;
            }
           
            t=t->next;
        }
        
        if(h1)
            t->next=h1;
        else
            t->next=h2;
        
        return h->next;
    }
    
    ListNode *findmid(ListNode* head)
    {
        ListNode *f,*s;
        f=s=head;
        
        while(f->next && f->next->next)
        {
            s=s->next;
            f=f->next->next;
        }
        
        f=s->next;
        s->next=NULL;
        
        return f;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *mid=findmid(head);
        mid=sortList(mid);
        head=sortList(head);
        head=merge(head,mid);
        
        return head;
    }
};