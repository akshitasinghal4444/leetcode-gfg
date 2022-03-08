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
    vector<int> postorderTraversal(TreeNode* root)
    {
        if(!root)
            return {};
        
        stack<TreeNode*> s1,s2;
        vector<int> ans;
        
        s1.push(root);
        
        while(!s1.empty())
        {
            root=s1.top();
            s1.pop();
            
            if(root->left)
                s1.push(root->left);
            if(root->right)
                s1.push(root->right);
            
            s2.push(root);
        }
        
        while(!s2.empty())
        {
            root=s2.top();
            s2.pop();
            ans.push_back(root->val);
        }
        return ans;
    }
    
    /*
    vector<int> postorderTraversal(TreeNode* root)
    {
        if(!root)
            return {};
        
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty())
        {
            TreeNode *n=s.top();
            
            if(n==NULL)
            {
                s.pop();
                ans.push_back(s.top()->val);
                s.pop();
            }
            else
            {
                s.push(NULL);
                
                if(n->right)
                    s.push(n->right);
                
                if(n->left)
                    s.push(n->left);
            }
        }
        return ans;
    }
    */
    
    /*
    vector<int> postorderTraversal(TreeNode* root)
    {
        if(!root)
            return {};
        
        vector<int> ans;
        stack<TreeNode*> s1,s2;
        
        s1.push(root);
        
        while(!s1.empty())
        {
            TreeNode *n=s1.top();
            s1.pop();
            s2.push(n);
            
            if(n->left)
                s1.push(n->left);
            
            if(n->right)
                s1.push(n->right);
        }
        
        while(!s2.empty())
        {
            TreeNode *n=s2.top();
            s2.pop();
            ans.push_back(n->val);
        }
        
        return ans;
    }
    */
    
    /*
    vector<int> ans;
    
    void postorder(TreeNode* root)
    {
        if(!root)
            return ;
        
        postorder(root->left);
        postorder(root->right);
        ans.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        ans={};
        postorder(root);
        return ans;
    }
    */
};