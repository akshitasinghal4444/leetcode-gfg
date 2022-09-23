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
    
    void traverse(TreeNode* root,vector<int> &a)
    {
        if(!root)
            return;
        
        if(!root->left && !root->right)
            a.push_back(root->val);
        else
        {
            traverse(root->left,a);
            traverse(root->right,a);
        }
    }
    
    bool leafSimilar(TreeNode* r1, TreeNode* r2) {
        vector<int> a1,a2;
        
        traverse(r1,a1);
        traverse(r2,a2);
        
        return a1==a2;
    }
};