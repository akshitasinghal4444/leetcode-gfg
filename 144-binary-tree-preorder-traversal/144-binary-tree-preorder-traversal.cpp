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
                
                while(t->right && t->right!=root)
                    t=t->right;
                
                if(t->right==NULL)
                {
                    t->right=root;
                    ans.push_back(root->val);
                    root=root->left;
                }
                else
                {
                    t->right=NULL;
                    root=root->right;
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
            root=s.top();
            s.pop();
            
            ans.push_back(root->val);
            
            if(root->right)
            s.push(root->right);
            
            if(root->left)
            s.push(root->left);
            
        }
        return ans;
    }
    */
    /*
    vector<int> preorderTraversal(TreeNode* root)
    {
        if(!root)
            return {};
        
        vector<int> ans;
        stack<TreeNode*> s;
        
        while(!s.empty() || root)
        {
            if(!root)
            {
                root=s.top()->right;
                s.pop();
            }
            else
            {
                ans.push_back(root->val);
                s.push(root);
                root=root->left;
            }
        }
        return ans;
    }
    */
    
    /*
    vector<int> ans;
    
    void preorder(TreeNode* root)
    {
        if(!root)
            return;
        
        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return ans;
    }
    */
};