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
    
    int deepestLeavesSum(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int ans=0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            ans=0;
            int s=q.size();
            
            while(s--)
            {
                root=q.front();
                q.pop();
                
                ans+=root->val;
                
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
        }
        return ans;
    }
    
    
    /*
    int ans=0,mx=-1;
    
    void sum(TreeNode* root,int level)
    {
        if(!root)
            return;
        
        if(level>mx)
        {
            ans=root->val;
            mx=level;
        }
        else if(level==mx)
            ans+=root->val;
        
        sum(root->left,level+1);
        sum(root->right,level+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        sum(root,0);
        return ans;
    }
    */
    
    
};