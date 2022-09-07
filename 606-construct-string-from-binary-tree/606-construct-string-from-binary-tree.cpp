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
    
    string tree2str(TreeNode* root) {
        if(!root)
            return "";
        
        string s=to_string(root->val);
        
        if(root->left)
            s+="(" + tree2str(root->left) + ")";
        
        if(root->right)
        {
            if(!root->left)
                s+="()";
            s+="(" + tree2str(root->right) + ")";
        }
        
        return s;
    }
    
    /*
    string s;
    
    void preorder(TreeNode* root)
    {
        if(!root)
            return ;
        
        s+='(';
        s+=to_string(root->val);
        
        if(!root->left && !root->right)
        {
            s+=')';
            return;
        }
        
        if(!root->left)
            s+="()";
        
        preorder(root->left);
        preorder(root->right);
        s+=')';
    }
    
    string tree2str(TreeNode* root) {
        s="";
        preorder(root);
        
        return s.substr(1,s.length()-2);
    }
    */
};