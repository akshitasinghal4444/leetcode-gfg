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
    vector<vector<int>> ans;
    vector<int> a;
    
    void check(TreeNode* root, int t)
    {
        if(!root)         
            return;
        
        a.push_back(root->val);
        t-=root->val;
        
        if(!root->left && !root->right)
        {
            if(t==0)
                ans.push_back(a);
        }
        else
        {
            check(root->left,t);
            check(root->right,t);
        }    
        
        a.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        
        check(root,t);
        return ans;
    }
};