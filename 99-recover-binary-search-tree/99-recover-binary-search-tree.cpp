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
    
    vector<int> v;
    int i;
    
    void store_inorder(TreeNode* root)
    {
        if(!root)
            return;
        
        store_inorder(root->left);
        v.push_back(root->val);
        store_inorder(root->right);
    }
    
    void change_inorder(TreeNode* root)
    {
        if(!root)
            return;
        
        change_inorder(root->left);
        root->val=v[i++];
        change_inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        store_inorder(root);
        sort(v.begin(),v.end());
        i=0;
        change_inorder(root);
    }
};