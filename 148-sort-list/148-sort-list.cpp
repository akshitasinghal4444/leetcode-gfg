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
    
    ListNode *mid(ListNode *h)
    {
        ListNode *s,*f;
        s=f=h;
        
        while(f->next && f->next->next)
        {
            s=s->next;
            f=f->next->next;
        }
        
        f=s->next;
        s->next=NULL;
        
        return f;
    }
    
    ListNode* merge(ListNode *left,ListNode *right)
    {
        if(!left)
            return right;
        if(!right)
            return left;
        
        ListNode *t,*h;
        
        if(left->val<=right->val)
        {
            t=left;
            left=left->next;
        }
        else
        {
            t=right;
            right=right->next;
        }
        
        h=t;
        while(left && right)
        {
            if(left->val<=right->val)
            {
                t->next=left;
                left=left->next;
            }
            else
            {
                t->next=right;
                right=right->next;
            }
            
            t=t->next;
        }
        
        if(left)
            t->next=left;
        else
            t->next=right;
        
        return h;
    }
    
    ListNode* sortList(ListNode* head)
    {
        if(!head || !head->next)
            return head;
        
        ListNode *left,*right;
        left=head;
        right=mid(left);
        
        left=sortList(left);
        right=sortList(right);
        
        left=merge(left,right);
        
        return left;
    }
    
    /*
    ListNode* findmid(ListNode* head)
    {
        ListNode *slow,*fast;
        slow=fast=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next= NULL;
        return fast;
    }
    
    ListNode *merge(ListNode* f,ListNode* s)
    {
        if(!f)
            return s;
        if(!s)
            return f;
        ListNode* t;
        if(f->val<=s->val)
        {
            t=f;
            t->next=merge(f->next,s);
        }
        else
        {
            t=s;
            t->next=merge(f,s->next);
        }
        return t;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *first,*second;
        first=head;
        second=findmid(head);
        first=sortList(first);
        second=sortList(second);
        head=merge(first,second);
        return head;
    }
    
    */
};