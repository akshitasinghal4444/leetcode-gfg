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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        
        if(root)
            q.push(root);
        
        while(!q.empty() )
        {
            int s=q.size();
            ans.push_back(q.back()->val);
            
            while(s--)
            {
                root=q.front();
                q.pop();
                        
                if(root->left)
                    q.push(root->left);
            
                if(root->right)
                    q.push(root->right);
            }
        }
        
        return ans;
    }
};