/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head)
            return NULL;
        
        unordered_map<Node*,Node*> m;
        
        Node *h,*t1,*t2;
        t1=new Node(0);
        h=t1;  
        t2=head;
        
        while(t2)
        {
            t1->next=new Node(t2->val);
            t1=t1->next;
            m[t2]=t1;
            t2=t2->next;
        }
        
        t2=head;
        t1=h->next;
        
        while(t2)
        {
            if(t2->random)
                t1->random=m[t2->random];
            else
                t2->random=NULL;
            
            t1=t1->next;
            t2=t2->next;
        }
        
        return h->next;
    }
};

/*
class Solution {
public:
    Node* copyRandomList(Node* h1)
    {
        Node *h2,*t1,*t2;
        h2=new Node(0);
        
        t1=h1;
        
        while(t1)
        {
            t2=new Node(t1->val);
            t2->next=t1->next;
            t1->next=t2;
            
            t1=t1->next->next;
        }
        
        t1=h1;
        while(t1)
        {
            t2=t1->next;
            if(t1->random==NULL)
                t2->random=NULL;
            else
                t2->random=t1->random->next;
            
            t1=t1->next->next;
        }
        
        t2=h2;
        t1=h1;
        while(t1)
        {
            t2->next=t1->next;
            t1->next=t1->next->next;
            t2=t2->next;
            t1=t1->next;
        }
        return h2->next;
    }
    */
    
    /*
    Node* copyRandomList(Node* h1)
    { 
        Node *h2,*t1,*t2;
        unordered_map<Node*,Node*> m;
        h2=new Node(0);
        t1=h1;
        t2=h2;
        
        while(t1)
        {
            t2->next=new Node(t1->val);
            m[t1]=t2->next;
            t2=t2->next;
            t1=t1->next;
        }
        t2->next=NULL;
        
        t1=h1;
        t2=h2->next;
        while(t1)
        {
            if(t1->random==NULL)
                t2->random=NULL;
            else
                t2->random=m[t1->random];
            
            t2=t2->next;
            t1=t1->next;
        }
        return h2->next;
    }
    */
    
    /*
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        
        Node *h2,*t1,*t2;
        t1=head;
        while(t1)
        {
            t2=new Node(t1->val);
            t2->next=t1->next;
            t1->next=t2;
            t1=t1->next->next;
        }
        
        t1=head;
        h2=head->next;
        
        while(t1)
        {
            t2=t1->next;
            if(!t1->random)
                t2->random=NULL;
            else
            t2->random=t1->random->next;
            t1=t1->next->next;
        }
        
        t1=head;
        
        
        while(t1)
        {
            t2=t1->next;
            t1->next=t2->next;
            if(t2->next)
            t2->next=t2->next->next;
            
            t1=t1->next;
        }
        
        return h2;
    }
        */