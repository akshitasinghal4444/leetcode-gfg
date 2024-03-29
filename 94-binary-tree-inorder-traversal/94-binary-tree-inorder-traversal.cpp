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
    vector<int> inorderTraversal(TreeNode* root)
    {
        if(!root)
            return {};
        
        vector<int> ans;
        
        while(root)
        {
            if(!root->left)
            {
                ans.push_back(root->val);
                root=root->right;
            }
            else
            {
                TreeNode *t=root->left;
                
                while(t->right!=NULL && t->right!=root)
                    t=t->right;
                
                if(t->right==NULL)
                {
                    t->right=root;
                    root=root->left;
                }
                else
                {
                    t->right=NULL;
                    ans.push_back(root->val);
                    root=root->right;
                }
            }
        }
        
        return ans;
    }
    
    /*
    vector<int> inorderTraversal(TreeNode* root)
    {
        if(!root)
            return {};
        
        vector<int> ans;
        stack<TreeNode*> s;
        
        while(root || !s.empty())
        {
            if(!root)
            {
                root=s.top();
                s.pop();
                
                ans.push_back(root->val);
                root=root->right;
            }
            else
            {
                s.push(root);
                root=root->left;
            }   
        }
        
        return ans;
    }
    */
    
    /*
    vector<int> ans;
    
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
    */
};