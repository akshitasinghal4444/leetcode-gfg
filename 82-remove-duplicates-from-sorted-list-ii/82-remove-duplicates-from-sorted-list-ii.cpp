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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *h,*temp=new ListNode();
        h=temp;
        temp->next=head;
        
        ListNode *n,*nn;
        
        while(temp && temp->next)
        {
            n=temp->next;
            nn=temp->next->next;
            
            if(nn && nn->val==n->val)
            {
                while(nn && nn->val==n->val)
                    nn=nn->next;
                
                temp->next=nn;
            }
            else
                temp=temp->next;
        }
        
        return h->next;
    }
};