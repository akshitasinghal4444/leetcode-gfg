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
    
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    
    bool findTarget(TreeNode* root, int k)
    {
        if(!root)
            return 0;
        
        inorder(root);
        
        int i=0,j=v.size()-1;
        
        while(i<j)
        {
            int s=v[i]+v[j];
            
            if(s==k)
                return 1;
            
            if(s<k)
                i++;
            else
                j--;
        }
        
        return 0;
    }
    
    /*
    unordered_set<int> s;
    
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return 0;
        
        if(s.find(k-root->val)!=s.end())
            return 1;
        
        s.insert(root->val);
        
        return findTarget(root->left,k) || findTarget(root->right,k);
    }
    */
    
};