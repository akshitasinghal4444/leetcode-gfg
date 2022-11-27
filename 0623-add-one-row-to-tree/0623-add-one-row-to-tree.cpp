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
    TreeNode* addOneRow(TreeNode* root, int val, int d) {
        
        if(d==1)
        {
            TreeNode *t=new TreeNode(val);
            t->left=root;
            return t;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            d--;
            int s=q.size();
            
            while(s--)
            {
                TreeNode *t=q.front();
                q.pop();
                
                if(d==1)
                {
                    TreeNode *t2=new TreeNode(val);
                    t2->left=t->left;
                    t->left=t2;
                    
                    t2=new TreeNode(val);
                    t2->right=t->right;
                    t->right=t2;
                }
                else
                {
                    if(t->left)
                        q.push(t->left);
                
                    if(t->right)
                        q.push(t->right);
                }
                
            }
        }
        
        return root;
    }
};