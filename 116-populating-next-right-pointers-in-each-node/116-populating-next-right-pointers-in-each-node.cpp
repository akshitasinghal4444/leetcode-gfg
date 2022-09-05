/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root)
    {
        if(!root)
            return root;
        
        Node *t1=root;
        
        while(t1)
        {
            Node *t2=t1;
            
            while(t2)
            {
                if(t2->left)
                    t2->left->next=t2->right;
                
                if(t2->right && t2->next)
                    t2->right->next=t2->next->left;
                
                t2=t2->next;
            }
            
            t1=t1->left;
        }
        return root;
    }
    
    /*
    Node* connect(Node* root)
    {
        if(!root)
            return root;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int s=q.size();
            
            while(s--)
            {
                Node *t=q.front();
                q.pop();
                
                if(s)
                    t->next=q.front();
                
                if(t->left)
                    q.push(t->left);
                
                if(t->right)
                    q.push(t->right);
            }
        }
        
        return root;
    }
    */
    
    /*
    Node* connect(Node* root) {
        if(!root)
            return root;
        
        if(root->left)
            root->left->next=root->right;
        
        if(root->right && root->next)
            root->right->next=root->next->left;
        
        root->left=connect(root->left);
        root->right=connect(root->right);
        
        return root;
    }
    */
};