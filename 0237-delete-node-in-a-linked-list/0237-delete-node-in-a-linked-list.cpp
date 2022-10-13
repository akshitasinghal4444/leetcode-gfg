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
    void deleteNode(ListNode* node)
    {
        ListNode *t=node->next;
        
        node->val=t->val;
        node->next=t->next;
        
        delete t;
    }
    
    /*
    void deleteNode(ListNode* node) {
        ListNode *t=node->next;
        
        while(t->next)
        {
            node->val=t->val;
            t=t->next;
            node=node->next;
        }
        
        node->val=t->val;
        node->next=NULL;
    }
    */
};