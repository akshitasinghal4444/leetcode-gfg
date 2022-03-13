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
    /*
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
    */
    
    
    int in_successor(TreeNode* root)
    {
        while(root->left)
            root=root->left;
        
        return root->val;
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
            
            root->val=in_successor(root->right);
            root->right=deleteNode(root->right,root->val);
            return root;
        }
        
        if(root->val>key)
            root->left=deleteNode(root->left,key);
        else
            root->right=deleteNode(root->right,key);
        
        return root;
    }
};