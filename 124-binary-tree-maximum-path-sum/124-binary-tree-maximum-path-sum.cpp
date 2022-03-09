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
    
    int sum(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int l,r;
        l=max(0,sum(root->left));
        r=max(0,sum(root->right));
        
        ans=max(ans,l+r+root->val);
        return max(l,r)+root->val;
    }
    
    int maxPathSum(TreeNode* root)
    {
        if(!root)
            return 0;
        
        ans=INT_MIN;
        int x=sum(root);
        return ans;
    }
    
    /*
    int m=INT_MIN;
    int ms(TreeNode* root)
    {
        int l=0,r=0;
        
        if(root->left)
        l=ms(root->left);
        
        if(root->right)
        r=ms(root->right);
        
        if(l<0)
            l=0;
        if(r<0)
            r=0;
        
        m=max(m,root->val+l+r);

        return max(l,r)+root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        m=max(ms(root),m);
        return m;
        
    }
    
    */
};