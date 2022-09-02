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
    int x,ans;
    
    void inorder(TreeNode* root, int k)
    {
        if(!root || ans!=-1)
            return;
        
        inorder(root->left,k);
        
        if(++x==k)
            ans=root->val;
        
        inorder(root->right,k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        if(!root)
            return -1;
        
        x=0,ans=-1;
        inorder(root,k);
        
        return ans;
    }
};