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
    
    void goodNodes(TreeNode* root,int mx)
    {
        if(!root)
            return;
        
        mx=max(root->val,mx);
        if(root->val>=mx)
            ans++;
        
        goodNodes(root->left,mx);
        goodNodes(root->right,mx);
    }
    
    int goodNodes(TreeNode* root) {
        ans=0;
        
        goodNodes(root,INT_MIN);
        
        return ans;
    }
};