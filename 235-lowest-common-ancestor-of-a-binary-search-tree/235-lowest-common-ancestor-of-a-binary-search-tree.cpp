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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        while(root)        
        {
            if(p->val<root->val && q->val<root->val)
                root=root->left;
            else if(p->val>root->val && q->val>root->val)
                root=root->right;
            else
                return root;
        }
        
        return root;
    }
    
    /*
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root)
            return root;
        
        if(p->val<root->val && q->val<root->val)
            return lowestCommonAncestor(root->left,p,q);
        
        if(p->val>root->val && q->val>root->val)
            return lowestCommonAncestor(root->right,p,q);
        
        return root;
    }
    */
    
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
        
        return r;
    }
    */
};