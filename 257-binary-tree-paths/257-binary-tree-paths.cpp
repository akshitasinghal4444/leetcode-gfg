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
    vector<string> ans;
    string t;
    
    void path(TreeNode* root)
    {
        if(!root)
            return;
       
        string s=t;
        t+=to_string(root->val);
        
        if(!root->left && !root->right)
        {
            ans.push_back(t);
            t=s;
            return;
        }
        
        t+="->";
        
        path(root->left);
        path(root->right);
        
        t=s;
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return {};
        
        ans={};
        t="";
        path(root);
        
        return ans;
    }
};