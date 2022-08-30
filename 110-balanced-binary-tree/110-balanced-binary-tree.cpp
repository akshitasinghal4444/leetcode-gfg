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
    bool bal;
    
    int height(TreeNode* root)
    {
        if(!root)
            return 0;
        
        if(!bal)
            return -1;
                
        int l=height(root->left);
        int r=height(root->right);
        
        if(abs(r-l)>1)
            bal=0;
        
        return 1+max(l,r);
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root)
            return 1;
        
        bal=1;
        int x=height(root);
        return bal;
    }
};