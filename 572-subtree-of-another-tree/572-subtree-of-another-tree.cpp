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
    bool check(TreeNode* root, TreeNode* sroot)
    {
        if(!root && !sroot)
            return 1;
        
        if(!root || !sroot || root->val!=sroot->val)
            return 0;
        
        return check(root->left,sroot->left) && check(root->right,sroot->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* sroot) {
        
        if(!root && !sroot)
            return 1;
        
        if(!root || !sroot)
            return 0;
        
        if(check(root,sroot))
            return 1;
        
        return isSubtree(root->left,sroot) || isSubtree(root->right,sroot);
    }
};