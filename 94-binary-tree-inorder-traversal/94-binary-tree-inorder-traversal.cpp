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
        
        stack<TreeNode*> st;
        vector<int> ans;
        
        while(root || !st.empty())
        {
            if(root)
            {
                st.push(root);
                root=root->left;
            }
            else
            {
                root=st.top();
                st.pop();
                ans.push_back(root->val);
                root=root->right;
            }
        }
        
        return ans;
    }
    
    /*
    vector<int> inorderTraversal(TreeNode* root)
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
                    t->right=curr;
                    curr=curr->left;
                }
                else
                {
                    t->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        
        return ans;
    }
    */
    
    /*
    vector<int> inorderTraversal(TreeNode* root)
    {
        if(!root)
            return {};
        
        vector<int> ans;
        stack<TreeNode*> s;
        
        while(root || !s.empty())
        {
            if(root)
            {
                s.push(root);
                root=root->left;
            }
            else
            {
                TreeNode *n=s.top();
                s.pop();
                
                ans.push_back(n->val);
                root=n->right;
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
        ans={};
        inorder(root);
        return ans;
    }
    */
};