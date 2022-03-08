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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        if(!root)
            return {};
        
        deque<TreeNode*> q;
        vector<vector<int>> ans;
        q.push_back(root);
        bool rev=0;
        
        while(!q.empty())
        {
            int s=q.size();
            vector<int> t;
            
            while(s--)
            {
                if(!rev)
                {
                    root=q.front();
                    q.pop_front();
                    
                    t.push_back(root->val);
                    
                    if(root->left)
                        q.push_back(root->left);
                    
                    if(root->right)
                        q.push_back(root->right);
                }                    
                else
                {
                    root=q.back();
                    q.pop_back();
                    
                    t.push_back(root->val);
                    
                    if(root->right)
                        q.push_front(root->right);
                    if(root->left)
                        q.push_front(root->left);
                }
            }
            ans.push_back(t);
            rev=!rev;
        }
        return ans;
    }
    
    /*
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        ans.push_back({root->val});
        q.push(root);
        bool flag=1;
        while(!q.empty())
        {
            int n=q.size();
            vector<int> t;
            while(n--)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left)
                {
                    q.push(temp->left);
                    t.push_back(temp->left->val);
                }
                    
                if(temp->right)
                {
                    q.push(temp->right);
                    t.push_back(temp->right->val);
                }
            }
            if(flag)
                    reverse(t.begin(),t.end());
            flag=!flag;     
            if(t.size()!=0)
            ans.push_back(t);
        }
        return ans;
    }
    */
};