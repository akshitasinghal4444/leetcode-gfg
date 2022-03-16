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
            return NULL;;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int s=q.size();
            
            while(s--)
            {
                Node *t=q.front();
                q.pop();
                
                if(s!=0)
                    t->next=q.front();
                
                if(t->left)
                    q.push(t->left);
                
                if(t->right)
                    q.push(t->right);
            }
        }
        
        return root;
    }
    
    /*
    Node* connect(Node* root)
    {
        if(!root)
            return root;
        if(root->left)
            root->left->next=root->right;
        if(root->next && root->right)
            root->right->next=root->next->left;

        root->left=connect(root->left);
        root->right=connect(root->right);
        return root;
    }
    */
    
    /*
    Node* connect(Node* root) {
        if(!root)
            return root;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            Node* t;
            int n=q.size();
            for(int i=0;i<n-1;i++)
            {
                t=q.front();
                q.pop(); 
                t->next=q.front();
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            t=q.front();
            q.pop(); 
            t->next=NULL;
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
        return root;
    }
    */
};