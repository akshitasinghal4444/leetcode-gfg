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
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        if(!root)
            return {};
        
        map<int,vector<pair<int,int>>> m;       // vertical index : (level,value)
        queue<pair<TreeNode*,int>> q;           // node,vertical index
        
        int l=0;
        
        q.push({root,0});
        
        while(!q.empty())
        {
            int s=q.size();
            l++;
            
            while(s--)
            {
                root=q.front().first;
                int i=q.front().second;
                q.pop();
            
                m[i].push_back({l,root->val});
            
                if(root->left)
                    q.push({root->left,i-1});
                
                if(root->right)
                    q.push({root->right,i+1});
            }
            
        }
        vector<vector<int>> ans;
        
        for(auto i:m)
        {
            sort(i.second.begin(),i.second.end());
            vector<int> t;
            
            for(auto x:i.second)
            t.push_back(x.second);
            
            ans.push_back(t);
        }
        
        return ans;
    }
    
    /*
    void level(TreeNode* root,int x,int y,map<int,multiset<pair<int,int>>> &m)
    {
        if(!root)
            return;
        m[y].insert({x,root->val});
        level(root->left,x+1,y-1,m);
        level(root->right,x+1,y+1,m);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,multiset<pair<int,int>>> m;
        level(root,0,0,m);
        for(auto it=m.begin();it!=m.end();it++)
        {
            vector<int> t;
            for(auto x : it->second)
                t.push_back(x.second);
            ans.push_back(t);
        }
            
        return ans;
    }
    */
};