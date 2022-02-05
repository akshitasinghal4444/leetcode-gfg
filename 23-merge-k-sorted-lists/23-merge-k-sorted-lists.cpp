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
    ListNode* merge(ListNode *a,ListNode *b)
    {
        ListNode *t=new ListNode(0),*ans;
        ans=t;
        
        while(a && b)
        {
            if(a->val<=b->val)
            {
                t->next=a;
                a=a->next;
            }
            else
            {
                t->next=b;
                b=b->next;
            }
            t=t->next;
        }
        
        if(a)
            t->next=a;
        else
            t->next=b;
        
        // while(ans->next)
        // {
        //     cout<<ans->next->val<<" ";
        //     ans=ans->next;
        // }
        // cout<<endl;
        return ans->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& a)
    {
        int n=a.size();
        if(n==0)
            return NULL;
        
        int i;
        ListNode* ans=a[0];
        
        
        
        for(i=1;i<n;i++)
        {
            ans=merge(ans,a[i]);
        }
        return ans;
    }
    
    /*
    ListNode* merge(ListNode* a,ListNode* b)
    {
        if(!a)
            return b;
        if(!b)
            return a;
        ListNode* t;
        if(a->val<=b->val)
        {
            t=a;
            t->next=merge(a->next,b);
        }
        else
        {
            t=b;
            t->next=merge(a,b->next);
        }
        return t;
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& a) {
        int n=a.size();
        if(n==0)
            return NULL;
        int i;
        ListNode* ans=a[0];
        for(i=1;i<n;i++)
        {
            ans=merge(ans,a[i]);
        }
        return ans;
    }
    */
};