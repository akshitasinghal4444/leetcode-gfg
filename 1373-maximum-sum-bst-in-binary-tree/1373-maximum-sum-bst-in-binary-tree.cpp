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
    
    vector<int> bst(TreeNode* root)
    {
        if(!root)
            return {INT_MIN,INT_MAX,INT_MIN};
        
        vector<int> l,r;
    
        l=bst(root->left);
        r=bst(root->right);
    
        if(l[2]>=root->val || r[1]<=root->val)
        	return {max(l[0],r[0]),INT_MIN,INT_MAX};
    
        int mn=min({root->val,l[1],r[1]});
        int mx=max({root->val,l[2],r[2]});
        int sum=root->val;
        
        if(l[0]!=INT_MIN)
            sum+=l[0];
        
        if(r[0]!=INT_MIN)
            sum+=r[0];
        
        ans=max({ans,sum,l[0],r[0]});
        
        // cout<<root->val<<" "<<sum<<" "<<ans<<endl;
        return {sum,mn,mx};
    }
    
    int maxSumBST(TreeNode* root) {
        if(!root)
            return 0;
        
        ans=0;
        auto v=bst(root);
        return ans;
    }
};