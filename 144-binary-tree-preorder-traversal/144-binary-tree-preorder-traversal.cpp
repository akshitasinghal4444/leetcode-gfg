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
    vector<int> preorderTraversal(TreeNode* root)
    {
        if(!root)
            return {};
        
        TreeNode *curr=root;
        vector<int> ans;
    
        while(curr)
        {
            if(!curr->left)
            {
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode *t=curr->left;
                
                while(t->right && t->right!=curr)
                    t=t->right;
                
                if(!t->right)
                {
                    ans.push_back(curr->val);
                    t->right=curr;
                    curr=curr->left;
                }
                else
                {
                    t->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
    
    /*
    vector<int> preorderTraversal(TreeNode* root)
    {
        if(!root)
            return {};
        
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty())
        {
            TreeNode *n=s.top();
            s.pop();
            ans.push_back(n->val);
            
            if(n->right)
                s.push(n->right);
            if(n->left)
                s.push(n->left);
        }
        
        return ans;
    }
    */
    
    /*
    vector<int> ans;
    
    void preorder(TreeNode* root)
    {
        if(!root)
            return ;
        
        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        ans={};
        preorder(root);
        return ans;
    }
    */
};