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
    int in;
    
    void inorder(TreeNode* root,int k)
    {
        if(!root)
            return;
        
        inorder(root->left,k);
        
        in++;
        if(in==k)
        {
            ans=root->val;
            return;
        }
        
        if(ans==-1)
            inorder(root->right,k);
    }
    
    int kthSmallest(TreeNode* root, int k)
    {
        ans=-1;
        in=0;
        inorder(root,k);
        return ans;
    }
    
    /*
    vector<int> v;
    
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
        
    int kthSmallest(TreeNode* root, int k)
    {
        inorder(root);
        return v[k-1];
    }
    */
    
};