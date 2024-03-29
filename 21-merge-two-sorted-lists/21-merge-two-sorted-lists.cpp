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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if(!l1)
            return l2;
        
        if(!l2)
            return l1;
        
        ListNode *t;
        if(l1->val<=l2->val)
        {
            t=l1;
            l1=l1->next;
        }
        else
        {
            t=l2;
            l2=l2->next;
        }
        t->next=mergeTwoLists(l1,l2);
        
        return t;
    }
    
    /*
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *t1,*t2;
        
        t1=new ListNode(0);
        t2=t1;
        
        while(l1 && l2)
        {
            if(l1->val<=l2->val)
            {
                t1->next=l1;
                l1=l1->next;
            }
            else
            {
                t1->next=l2;
                l2=l2->next;
            }
            
            t1=t1->next;
        }
        
        while(l1)
        {
            t1->next=l1;
            l1=l1->next;
            t1=t1->next;
        }
        
        while(l2)
        {
            t1->next=l2;
            l2=l2->next;
            t1=t1->next;
        }
        
        return t2->next;
    }
    */
};