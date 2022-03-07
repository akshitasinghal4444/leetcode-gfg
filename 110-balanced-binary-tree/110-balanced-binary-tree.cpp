/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool bal;
    
    int check(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int l,r;
        l=check(root->left);
        r=check(root->right);
        
        if(abs(l-r)>1)
            bal=0;
        
        return max(l,r)+1;
    }
    
    bool isBalanced(TreeNode* root)
    {
        if(!root)
            return 1;
        
        bal=1;
        
        int h=check(root);
        
        return bal;
    }
    
    /*
    unordered_map<TreeNode*,int> m;
    
    int height(TreeNode* root)
    {
        if(!root)
            return 0;
        
        if(m.find(root)==m.end())
            m[root]=max(height(root->left),height(root->right))+1;
        
        return m[root];
    }
    
    bool isBalanced(TreeNode* root) {
        
        if(!root)
            return 1;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            root=q.front();
            q.pop();
            
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
            
            int l=height(root->left);
            int r=height(root->right);
            
            if(abs(l-r)<=1)
                continue;
            else
                return 0;   
        }
        return 1;
    }
    */
};