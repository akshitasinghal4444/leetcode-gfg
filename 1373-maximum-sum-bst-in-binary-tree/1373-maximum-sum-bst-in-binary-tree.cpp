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
    
    int ans=0;
    
    vector<int> check(TreeNode* root)               // {min,max,sum}
    {
        if(!root)
            return {INT_MAX,INT_MIN,0};
        
        vector<int> l=check(root->left);
        vector<int> r=check(root->right);
        
        if(l[1]<root->val && r[0]>root->val)
        {
            int s=l[2]+r[2]+root->val;
            ans=max(ans,s);
            
            return {min(l[0],root->val),max(root->val,r[1]),s};
        }   
        
        
        return {INT_MIN,INT_MAX,0};
    }
    
    int maxSumBST(TreeNode* root) {
        
        auto v=check(root);
        return ans;
    }
};