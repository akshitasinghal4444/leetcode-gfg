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
    
    void path(TreeNode* root, int t,long sum)
    {
        if(!root)
            return;
        
        sum+=root->val;
        
        if(sum==t)
            ans++;

        path(root->left,t,sum);
        path(root->right,t,sum);
        
    }
    
    int pathSum(TreeNode* root, int t) {
        
        if(!root)
            return 0;
                
        path(root,t,0);
        pathSum(root->left,t);
        pathSum(root->right,t);
        
        return ans;
    }
    
    /*
    unordered_map<long,int> m;
    int ans;
    
    void path(TreeNode* root, int t,long sum)
    {
        if(!root)
            return;
        
        sum+=root->val;
        
        if(m[sum-t]>0)
            ans+=m[sum-t];

        m[sum]++;
        
        path(root->left,t,sum);
        path(root->right,t,sum);
        
        m[sum]--;
        
        
    }
    
    int pathSum(TreeNode* root, int t) {
        ans=0;
        m[0]++;
        
        path(root,t,0);
        
        return ans;
    }
    */
};