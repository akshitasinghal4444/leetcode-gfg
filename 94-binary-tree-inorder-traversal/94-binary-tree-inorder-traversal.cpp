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
    vector<int> inorderTraversal(TreeNode* root)
    {
        if(!root)
            return {};
        
        vector<int> ans;
        stack<TreeNode*> s;
        
        while(root || !s.empty())
        {
            if(root)
            {
                s.push(root);
                root=root->left;
            }
            else
            {
                TreeNode *n=s.top();
                s.pop();
                
                ans.push_back(n->val);
                root=n->right;
            }
        }
        return ans;
    }
    
    /*
    vector<int> ans;
    
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        ans={};
        inorder(root);
        return ans;
    }
    */
};