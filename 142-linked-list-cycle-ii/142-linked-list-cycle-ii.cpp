/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        if(!head)
            return NULL;
        
        ListNode *s,*f;
        s=f=head;
        bool cycle=0;
        
        while(f->next && f->next->next)
        {
            s=s->next;
            f=f->next->next;
            
            if(s==f)
            {
                cycle=1;
                break;
            }
        }
        
        if(!cycle)
            return NULL;
        
        f=head;
        while(s!=f)
        {
            s=s->next;
            f=f->next;
        }
        return s;
    }
};