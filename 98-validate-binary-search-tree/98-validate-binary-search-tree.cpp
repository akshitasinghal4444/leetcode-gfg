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
    long x;
    
    bool inorder(TreeNode* root)
    {
        if(!root)
            return 1;
        
        if(!inorder(root->left) || root->val<=x)
            return 0;
        
        x=root->val;
        return inorder(root->right);
        
    }
    
    bool isValidBST(TreeNode* root) {
        x=LONG_MIN;
        return inorder(root);
    }
};