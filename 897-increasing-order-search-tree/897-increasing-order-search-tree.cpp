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
    
    void helper(TreeNode* root)
    {
        if(!root)
            return;
        
        helper(root->left);
        
        root->left=NULL;
        r2->right=root;
        r2=r2->right;
        
        
//         cout<<root->val<<":";
        
//         if(root->left)
//         cout<<root->left->val;
//         cout<<" ";
        
//         if(root->right)
//         cout<<root->right->val;
//         cout<<endl;
        
        helper(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        
        r2=new TreeNode();
        TreeNode* r3=r2;
        
        helper(root);
        
        return r3->right;
    }
};