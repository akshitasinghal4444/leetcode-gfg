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
    
    TreeNode* r2;
    
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        
        inorder(root->left);
        
        // root->left=NULL;
        r2->right=new TreeNode(root->val);
        r2=r2->right;
        
        inorder(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        
        r2=new TreeNode();
        TreeNode* r3=r2;
        
        inorder(root);
        
        return r3->right;
    }
    
    /*
    TreeNode* r2;
    
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        
        inorder(root->left);
        
        root->left=NULL;
        r2->right=root;
        r2=r2->right;
        
        inorder(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        
        r2=new TreeNode();
        TreeNode* r3=r2;
        
        inorder(root);
        
        return r3->right;
    }
    */
};