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
    vector<int> postorderTraversal(TreeNode* root)
    {
        if(!root)
            return {};
        
        vector<int> ans;
        stack<TreeNode*> s1,s2;
        
        s1.push(root);
        
        while(!s1.empty())
        {
            TreeNode *n=s1.top();
            s1.pop();
            s2.push(n);
            
            if(n->left)
                s1.push(n->left);
            
            if(n->right)
                s1.push(n->right);
        }
        
        while(!s2.empty())
        {
            TreeNode *n=s2.top();
            s2.pop();
            ans.push_back(n->val);
        }
        
        return ans;
    }
    
    /*
    vector<int> ans;
    
    void postorder(TreeNode* root)
    {
        if(!root)
            return ;
        
        postorder(root->left);
        postorder(root->right);
        ans.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        ans={};
        postorder(root);
        return ans;
    }
    */
};