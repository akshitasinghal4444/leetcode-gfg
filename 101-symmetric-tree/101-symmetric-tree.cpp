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
    bool isSymmetric(TreeNode* root) {
        
        if(!root)
            return 1;
        
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while(!q.empty())
        {
            TreeNode *l,*r;
            
            l=q.front();
            q.pop();
            
            r=q.front();
            q.pop();
            
            if(!l && !r)
                continue;
            
            if(!l || !r || l->val!=r->val)
                return 0;
            
            q.push(l->left);
            q.push(r->right);
            
            q.push(l->right);
            q.push(r->left);
        }
        return 1;
    }
    
    /*
    bool isSymmetric(TreeNode* l,TreeNode* r)
    {
        if(!l && !r)
            return 1;
        
        if(!l || !r || l->val!=r->val)
            return 0;
        
        return isSymmetric(l->left,r->right) && isSymmetric(l->right,r->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return 1;
        
        return isSymmetric(root->left,root->right);
    }
    */
};