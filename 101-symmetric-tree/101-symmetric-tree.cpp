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
    bool check(TreeNode *r1,TreeNode *r2)
    {
        if(!r1 && !r2)
            return 1;
        
        if(!r1 || !r2 || r1->val!=r2->val)
            return 0;
        
        return check(r1->left,r2->right) && check(r2->left,r1->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return 1;
        
        return check(root->left,root->right);
    }
    */
};