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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int ans=0;
        queue<pair<TreeNode*,long>> q;
        q.push({root,0});
        
        while(!q.empty())
        {
            int st=q.front().second;
            int end=q.back().second;
            ans=max(ans,end-st+1);
            
            int s=q.size();
            while(s--)
            {
                root=q.front().first;
                long in=q.front().second-st;
                q.pop();
                
                if(root->left)
                    q.push({root->left,2*in+1});
                
                if(root->right)
                    q.push({root->right,2*in+2});
            }
        }
        
        return ans;
    }
};