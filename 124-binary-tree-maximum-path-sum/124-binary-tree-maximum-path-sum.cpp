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
    int ans;
    
    int sum(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int l=sum(root->left);
        int r=sum(root->right);
        
        ans=max({ans,root->val,root->val+l,root->val+r,root->val+l+r});
        
        return root->val+max({0,l,r});
    }
    
    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        int s=sum(root);
        return ans;
    }
};