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
    
    bool inorder(TreeNode* root)
    {
        if(!root)
            return 1;
        
        if(!inorder(root->left))
            return 0;
        
        if(t==NULL || root->val>t->val)
            t=root;
        else
            return 0;
        
        return inorder(root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root)
            return 1;
        
        t=NULL;
        return inorder(root);
    }
    
    /*
    long a;
    
    bool inorder(TreeNode* root)
    {
        if(!root)
            return 1;
        
        bool x=inorder(root->left);
        if(!x)
            return 0;
        
        if(root->val>a)
            a=root->val;
        else
            return 0;
        
        return inorder(root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root)
            return 1;
        
        a=LONG_MIN;
        return inorder(root);
    }
    */
};