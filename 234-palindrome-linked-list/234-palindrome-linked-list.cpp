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
    bool isPalindrome(ListNode* head) {
        ListNode *s,*f,*p,*n;
        s=f=head;
        p=NULL;
        
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
            if(s->val!=p->val)
                return 0;
            s=s->next;
            p=p->next;
        }
        
        return 1;
    }
};