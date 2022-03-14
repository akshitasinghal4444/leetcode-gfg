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
    TreeNode* invertTree(TreeNode* root)
    {
        if(!root)
            return root;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode *t=q.front();
            q.pop();
            
            TreeNode *x=t->left;
            t->left=t->right;
            t->right=x;
            
            if(t->left)
                q.push(t->left);
            
            if(t->right)
                q.push(t->right);
        }
        
        return root;
    }
    
    /*
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        
        TreeNode *l,*r;
        l=invertTree(root->left);
        r=invertTree(root->right);
        
        root->left=r;
        root->right=l;
        
        return root;
    }
    */
};