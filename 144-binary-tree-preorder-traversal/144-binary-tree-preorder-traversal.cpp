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
    vector<int> preorderTraversal(TreeNode* root)
    {
        if(!root)
            return {};
        
        vector<int> ans;
        stack<TreeNode*> s;
        
        while(!s.empty() || root)
        {
            if(!root)
            {
                root=s.top()->right;
                s.pop();
            }
            else
            {
                ans.push_back(root->val);
                s.push(root);
                root=root->left;
            }
        }
        return ans;
    }
    
    /*
    vector<int> ans;
    
    void preorder(TreeNode* root)
    {
        if(!root)
            return;
        
        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return ans;
    }
    */
};