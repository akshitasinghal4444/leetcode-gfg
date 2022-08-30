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
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)
            return {};
        
        vector<vector<int>> ans;
        map<int,vector<pair<int,int>>> m;
        queue<pair<TreeNode* ,int>> q;
        int level=0;
        
        q.push({root,0});
        
        while(!q.empty())
        {
            int s=q.size();
            
            while(s--)
            {
                root=q.front().first;
            int in=q.front().second;
            q.pop();
            
            m[in].push_back({level,root->val});
            
            if(root->left)
                q.push({root->left,in-1});
            
            if(root->right)
                q.push({root->right,in+1});
            }
                            
            level++;
        }
        
        for(auto it:m)
        {
            sort(it.second.begin(),it.second.end());
            vector<int> t;
            
            for(auto p:it.second)
            t.push_back(p.second);
            
            ans.push_back(t);
        }
            
        
        return ans;
    }
};