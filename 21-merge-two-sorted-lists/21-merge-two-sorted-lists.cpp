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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        ListNode *t,*h;
        
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
        h=t;
        
        while(l1 && l2)
        {
            if(l1->val<=l2->val)
            {
                t->next=l1;
                l1=l1->next;
            }
            else
            {
                t->next=l2;
                l2=l2->next;
            }
            
            t=t->next;
        }
        
        if(!l1)
            t->next=l2;
        else
            t->next=l1;
        
        return h;
    }
    */
   
};