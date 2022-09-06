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
    unordered_set<int> s;
    
    bool find(TreeNode* root, int k)
    {
        if(!root)
            return 0;
        
        if(s.find(k-root->val)!=s.end())
            return 1;
        
        s.insert(root->val);
        
        return find(root->left,k) || find(root->right,k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        return find(root,k);
    }
};