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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        
        if(!head || !head->next || l==r)
            return head;
        
        int l2=l;
        ListNode *t=head;
        l--;
        while(l>1)
        {
            t=t->next;
            l--;
        }
        
        ListNode *p,*t1,*t2;
        
        if(l!=0)
        {
            p=t;
            t1=p->next;
            t2=t1->next;
        }
        else
        {
            t=NULL;
            p=NULL;
            t1=head;
        }
        
        int i=l2;
        while(i<=r)
        {
            t2=t1->next;
            t1->next=p;
            p=t1;
            t1=t2;
            i++;
        }
        
        if(l!=0)
        {t->next->next=t1;
        t->next=p;}
        else
        {
            head->next=t1;
            head=p;
        }
        
        return head;
    }
};