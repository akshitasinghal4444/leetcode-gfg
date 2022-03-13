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
    int in_successor(TreeNode* root)
    {
        TreeNode* t=root->right;
        int x;
        
        if(!t->left)
        {
            x=t->val;
            root->right=deleteNode(t,x);
        }
        else
        {
            while(t->left->left)
            t=t->left;
            
            x=t->left->val;
            t->left=deleteNode(t->left,x);
        }
        
        return x;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        
        if(root->val==key)
        {
            if(!root->left && !root->right)
                return NULL;
            
            if(!root->right)
                return root->left;
            
            if(!root->left)
                return root->right;
            
            root->val=in_successor(root);

            return root;
        }
        
        if(root->val>key)
            root->left=deleteNode(root->left,key);
        else
            root->right=deleteNode(root->right,key);
        
        return root;
    }
    
    
    /*
    TreeNode* in_successor(TreeNode* root)
    {
        TreeNode* t=root->right;
        while(t->left)
            t=t->left;
        
        return t;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        
        if(root->val==key)
        {
            if(!root->left && !root->right)
                return NULL;
            
            if(!root->right)
                return root->left;
            
            if(!root->left)
                return root->right;
            
            TreeNode *t=in_successor(root);
            root->val=t->val;
            root->right=deleteNode(root->right,t->val);
            return root;
        }
        
        if(root->val>key)
            root->left=deleteNode(root->left,key);
        else
            root->right=deleteNode(root->right,key);
        
        return root;
    }
    */
};