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
    int i;
    vector<int> a;
    
    void traverse(TreeNode* root)
    {
        if(!root)
            return;
        
        if(!root->left && !root->right)
            a.push_back(root->val);
        else
        {
            traverse(root->left);
            traverse(root->right);
        }
    }
    
    
    bool check(TreeNode* root)
    {
        if(!root)
            return 1;
        
        if(!root->left && !root->right)
        {
            if(i==a.size() || a[i]!=root->val)
            return 0;
            
            i++;
        }
        
        return check(root->left) && check(root->right);
    }
    
    bool leafSimilar(TreeNode* r1, TreeNode* r2) {
        
        traverse(r1);
        i=0;
        return check(r2) && i==a.size();
    }
    
    /*
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
    */
};