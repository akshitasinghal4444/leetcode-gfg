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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *t1,*t2,*h1,*h2;
        t1=new ListNode(),t2=new ListNode();
        h1=t1,h2=t2;
        
        while(head && head->next)
        {
            t1->next=head;
            head=head->next;
            t1=t1->next;
            
            t2->next=head;
            head=head->next;
            t2=t2->next;
        }
        
        if(head)
        {
            t1->next=head;
            t1=t1->next;
        }
        
        t2->next=NULL;
        t1->next=h2->next;
        return h1->next;
    }
};