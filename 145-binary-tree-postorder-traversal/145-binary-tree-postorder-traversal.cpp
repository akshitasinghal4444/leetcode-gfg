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
        
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty())
        {
            root=s.top();
            
            if(!root)
            {
                s.pop();
                ans.push_back(s.top()->val);
                s.pop();
            }
            else
            {
                s.push(NULL);
                
                if(root->right)
                    s.push(root->right);
                
                if(root->left)
                    s.push(root->left);
            }
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
        
        while(root || !s.empty())
        {
            if(!root)
            {
                while(!s.empty() && !s.top())
                {
                    s.pop();
                    ans.push_back(s.top()->val);
                    s.pop();                    
                }
                
                if(!s.empty())
                {
                    root=s.top()->right;
                    s.push(NULL);
                }
                    
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
    
    void postorder(TreeNode* root)
    {
        if(!root)
            return;
        
        postorder(root->left);
        postorder(root->right);
        
        ans.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return ans;
    }
    */
};