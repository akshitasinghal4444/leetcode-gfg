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
            return ;
        
        TreeNode *l,*r;
        l=root->left;
        r=root->right;
        
        t->right=root;
        root->left=NULL;
        t=t->right;
        
        preorder(l);
        preorder(r);
    }
    
    void flatten(TreeNode* root) {
        
        if(!root)
            return ;
        
        TreeNode *h;
        t=new TreeNode(0);
        h=t;
        preorder(root);
        
        root=h->right;
    }
};