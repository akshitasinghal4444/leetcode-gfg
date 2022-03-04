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
    ListNode* mergeInBetween(ListNode* l1, int a, int b, ListNode* l2) {
        int i=0;
        ListNode *st,*end,*t;
        t=l1;
        
        while(i<a-1)
        {
            t=t->next;
            i++;
        }
        st=t;
        
        while(i<b)
        {
            t=t->next;
            i++;
        }
        end=t->next;
        
        st->next=l2;
        
        while(l2->next)
            l2=l2->next;
        
        l2->next=end;
        
        return l1;
    }
};