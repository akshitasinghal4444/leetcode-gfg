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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root)
            return {};
        
        vector<double> ans;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int s=q.size();
            double sum=0;
            
            for(int i=0;i<s;i++)
            {
                root=q.front();
                q.pop();
                
                sum+=root->val;
                
                if(root->left)
                    q.push(root->left);
                
                if(root->right)
                    q.push(root->right);
            }
            
            ans.push_back(sum/s);
        }
        
        return ans;
    }
};