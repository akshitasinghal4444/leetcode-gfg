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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *t,*h;
        t=new ListNode(0);
        h=t;
        int sum=0;
        
        while(l1 || l2 || sum)
        {
            int a=0,b=0;
            
            if(l1)
            {
                a=l1->val;
                l1=l1->next;
            }
            
            if(l2)
            {
                b=l2->val;
                l2=l2->next;
            }
            
            sum+=a+b;
            t->next=new ListNode(sum%10);
            t=t->next;
            sum=sum/10;
        }
        return h->next;
    }
    
    /*
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* ans=new ListNode(0);
        ListNode* h=ans;
        int sum=0;
        
        while(l1 || l2 || sum)
        {
            if(l1)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            ListNode* t=new ListNode(sum%10);
            h->next=t;
            sum=sum/10;
            h=h->next;
        }
        return ans->next;
    }
    */
    
    /*
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode(0);
        ListNode* h=ans;
        int sum=0;
        while(l1 && l2)
        {
            
            sum+=l1->val+l2->val;
            if(sum>=0 && sum<=9)
            {
                ListNode* t=new ListNode(sum);
                h->next=t;
                sum=0;
            }
            else
            {
                ListNode* t=new ListNode(sum%10);
                h->next=t;
                sum=sum/10;
            }
            l1=l1->next;
            l2=l2->next;
            h=h->next;
        }
        
        while(l1)
        {
            sum+=l1->val;
            if(sum>=0 && sum<=9)
            {
                ListNode* t=new ListNode(sum);
                h->next=t;
                sum=0;
            }
            else
            {
                ListNode* t=new ListNode(sum%10);
                h->next=t;
                sum=sum/10;
            }
            l1=l1->next;
            h=h->next;
        }
        while(l2)
        {
            sum+=l2->val;
            if(sum>=0 && sum<=9)
            {
                ListNode* t=new ListNode(sum);
                h->next=t;
                sum=0;
            }
            else
            {
                ListNode* t=new ListNode(sum%10);
                h->next=t;
                sum=sum/10;
            }
            l2=l2->next;
            h=h->next;
        }
        while(sum)
        {
            if(sum>=0 && sum<=9)
            {
                ListNode* t=new ListNode(sum);
                h->next=t;
                sum=0;
            }
            else
            {
                ListNode* t=new ListNode(sum%10);
                h->next=t;
                sum=sum/10;
            }
            h=h->next;
        }
        return ans->next;
    }
    */
};