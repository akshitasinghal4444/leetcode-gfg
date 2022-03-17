/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root)
            return NULL;
        
        if(root==p || root==q || (p->val<root->val && q->val>root->val) || (q->val<root->val && p->val>root->val))
            return root;
        
        
        if(p->val<root->val)
        return lowestCommonAncestor(root->left,p,q);
        else
        return lowestCommonAncestor(root->right,p,q);
        
    }
    
    /*
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root)
            return NULL;
        
        if(root==p || root==q)
            return root;
        
        TreeNode *l,*r;
        l=lowestCommonAncestor(root->left,p,q);
        r=lowestCommonAncestor(root->right,p,q);
        
        if(l && r)
            return root;
        
        if(l)
            return l;
        else
            return r;
    }
    */
};