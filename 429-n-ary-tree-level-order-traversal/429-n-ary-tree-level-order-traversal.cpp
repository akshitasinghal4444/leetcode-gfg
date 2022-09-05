/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        if(!root)
            return {};
        
        queue<Node*> q;
        vector<vector<int>> ans;
        q.push(root);
        
        while(!q.empty())
        {
            int s=q.size();
            vector<int> t;
            
            while(s--)
            {
                root=q.front();
                q.pop();
                
                t.push_back(root->val);
                
                for(auto node:root->children)
                    q.push(node);
            }
            
            ans.push_back(t);
        }
        
        return ans;
    }
};