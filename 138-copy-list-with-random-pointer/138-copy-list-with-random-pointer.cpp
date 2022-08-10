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
    Node* copyRandomList(Node* h1) {
        unordered_map<Node*,Node*> m;
        
        Node *h2=new Node(0),*t2=h2,*t1=h1;
        while(t1)
        {
            t2->next=new Node(t1->val);
            m[t1]=t2->next;
            
            t2=t2->next;
            t1=t1->next;
        }
        
        h2=h2->next;
        t1=h1;
        t2=h2;
        
        while(t1)
        {
            if(t1->random)
                t2->random=m[t1->random];
            
            t1=t1->next;
            t2=t2->next;
        }
        
        return h2;
    }
};