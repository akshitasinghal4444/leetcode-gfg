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
    int maxDepth(TreeNode* root)
    {
        if(!root)
            return 0;
        
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
    
    /*
    int maxDepth(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int d=0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int s=q.size();
            d++;
            while(s--)
            {
                TreeNode* t=q.front();
                q.pop();
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
        }
        return d;
    }
    */
};