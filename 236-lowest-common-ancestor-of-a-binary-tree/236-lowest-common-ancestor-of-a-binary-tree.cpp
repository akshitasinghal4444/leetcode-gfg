/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool path(TreeNode* root, TreeNode* p,vector<TreeNode*> &v)
    {
        if(!root)
            return 0;
        
        v.push_back(root);
        
        if(root==p)
            return 1;
        
        bool l,r;
        l=path(root->left,p,v);
        
        if(!l)
            r=path(root->right,p,v);
        
        if(!l && !r)
        {
            v.pop_back();
            return 0;
        }
            
        return 1;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        vector<TreeNode*> v1,v2;
        bool x=path(root,p,v1);
        x=path(root,q,v2);
        
        int n=min(v1.size(),v2.size()),i;
        
        for(i=0;i<n;i++)
        {
            if(v1[i]!=v2[i])
                break;
        }
        
        return v1[i-1];
    }
    
    /*
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        
        if(root==p || root==q)
            return root;
        
        TreeNode *l,*r;
        l=lowestCommonAncestor(root->left,p,q);
        r=lowestCommonAncestor(root->right,p,q);
        
        if(l && r)
            return root;
        
        if(l)
            return l;
        return r;
    }
    */
};