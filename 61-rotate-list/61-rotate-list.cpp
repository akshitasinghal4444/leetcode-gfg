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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(!head || !head->next)
            return head;
        
        int l=1;
        ListNode *t=head;
        
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
        
        for(int i=0;i<l-k-1;i++)
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
            l++;
            head=head->next;
        }
        
        return l;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)
            return head;
        
        int l=len(head);
        k=k%l;
        
        if(k==0)
            return head;
        
        ListNode *t1,*t2;
        t1=t2=head;
        while(k--)
            t1=t1->next;
        
        while(t1->next)
        {
            t1=t1->next;
            t2=t2->next;
        }
        
        t1->next=head;
        head=t2->next;
        t2->next=NULL;
        
        return head;
    }
    */
};