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
    TreeNode *t; 
    
    void preorder(TreeNode* root)
    {
        if(!root)
            return;
        
        TreeNode *x=root->right;
        t->right=root;
        t=t->right;
        
        preorder(root->left);
        root->left=NULL;
        preorder(x); 
    }
    
    void flatten(TreeNode* root) {
        t=new TreeNode(0);
        TreeNode *h=t;
        
        preorder(root);
        
        root=h->right;
    }
};