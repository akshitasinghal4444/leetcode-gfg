/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* dfs(Node *node,unordered_map<int,Node*> &m)
    {
        if(node==NULL)
            return NULL;
        
        if(m.find(node->val)==m.end())
        {
            Node *t=new Node(node->val);
            m[node->val]=t;
            for(Node *n:node->neighbors)
            {
                t->neighbors.push_back(dfs(n,m));
            }
        }
        return m[node->val];
    }
    
    Node* cloneGraph(Node* node) {
        
        if(node==NULL)
            return NULL;
        
        unordered_map<int,Node*> m;
        
        return dfs(node,m);
    }
    
    /*
    Node* dfs(Node *node,unordered_map<Node*,Node*> &m)
    {
        if(node==NULL)
            return NULL;
        
        if(m.find(node)==m.end())
        {
            Node *t=new Node(node->val);
            m[node]=t;
            for(Node *n:node->neighbors)
            {
                t->neighbors.push_back(dfs(n,m));
            }
        }
        return m[node];
    }
    
    Node* cloneGraph(Node* node) {
        
        if(node==NULL)
            return NULL;
        
        unordered_map<Node*,Node*> m;
        
        return dfs(node,m);
    }
    */
};