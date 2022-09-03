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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        bool f=1;
        
        q.push(root);
        
        while(!q.empty())
        {
            int s=q.size();
            vector<int> t;
            
            while(s--)
            {
                root=q.front();
                q.pop();
                
                t.push_back(root->val);
                
                if(root->left)
                    q.push(root->left);
                
                if(root->right)
                    q.push(root->right);
            }
            
            if(!f)
                reverse(t.begin(),t.end());
            
            f=!f;
            
            ans.push_back(t);
        }
        
        return ans;
    }
};