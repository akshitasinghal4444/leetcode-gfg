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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3=new ListNode(0),*t=l3;
        int c=0;
        
        while(l1 || l2 || c)
        {
            int x=0;
            
            if(l1)
            {
                x+=l1->val;
                l1=l1->next;
            }
            
            if(l2)
            {
                x+=l2->val;
                l2=l2->next;
            }
            
            x+=c;
            
            t->next=new ListNode(x%10);
            t=t->next;
            c=x/10;
        }
        
        return l3->next;
    }
};