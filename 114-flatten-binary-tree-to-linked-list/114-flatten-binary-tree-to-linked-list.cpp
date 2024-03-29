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
    void flatten(TreeNode* root)
    {
        if(!root)
            return;
        
        flatten(root->left);
        flatten(root->right);
        
        if(root->left)
        {
            TreeNode *t=root->left;
            while(t->right)
                t=t->right;
            
            t->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }
    }
    
    /*
    TreeNode *t; 
    
    void preorder(TreeNode* root)
    {
        if(!root)
            return;
        
        TreeNode *l=root->left;
        TreeNode *r=root->right;
        
        t->right=root;
        t=t->right;
        t->left=NULL;
        
        preorder(l);
        preorder(r); 
    }
    
    void flatten(TreeNode* root) {
        t=new TreeNode(0);
        TreeNode *h=t;
        
        preorder(root);
        
        root=h->right;
    }
    */
};