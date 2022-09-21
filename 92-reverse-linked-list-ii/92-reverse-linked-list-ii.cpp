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
    ListNode* reverseBetween(ListNode* head, int l, int r)
    {
        if(!head || !head->next || l==r)
            return head;
        
        ListNode *temp=new ListNode(0);
        temp->next=head;
        
        int i;
        ListNode *t1=temp,*cur,*prev,*nex,*t;
            
        for(i=0;i<l-1;i++)
            t1=t1->next;
        
        cur=t=t1->next;
        prev=NULL;
        
        for(i=l;i<=r;i++)
        {
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
        }
        
        t->next=cur;
        t1->next=prev;
        
        return temp->next;
    }
    
    /*
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        
        if(!head || !head->next || l==r)
            return head;

        ListNode *t,*t1,*cur,*prev,*nex;
        t1=head;
        int i=l-1;
        
        while(i>1)
        {
            i--;
            t1=t1->next;
        }
        
        if(i==0)
        {
            t1=NULL;
            cur=head;
        }
        else
            cur=t1->next;
        
        i=l;
        t=cur;
        prev=NULL;
        
        while(i++<=r)
        {
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
        }
        
        t->next=cur;     
        
        if(t1)
        {
            t1->next=prev;
            return head;
        }
              
        return prev;
    }
    */
};