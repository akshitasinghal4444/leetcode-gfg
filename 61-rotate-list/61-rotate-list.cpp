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
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        
        ListNode *t;
        int l=1;
        t=head;
        
        while(t->next)
        {
            l++;
            t=t->next;
        }
        
        k=k%l;
        if(k==0)
            return head;
        
        t->next=head;
        t=head;
        
        for(int i=0;i<(l-k-1);i++)
            t=t->next;
        
        head=t->next;
        t->next=NULL;

        return head;
    }
    
    
    /*
    int len(ListNode* head)
    {
        int l=0;
        while(head)
        {
            head=head->next;
            l++;
        }
        return l;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        
        int l=len(head);
        
        k=k%l;
        if(k==0)
            return head;
        
        ListNode *f,*s;
        f=s=head;
        int i=0;
        while(i++<k)
        {
            f=f->next;
        }
        while(f->next)
        {
            f=f->next;
            s=s->next;
        }
        f->next=head;
        head=s->next;
        s->next=NULL;

        return head;
    }
    */
};