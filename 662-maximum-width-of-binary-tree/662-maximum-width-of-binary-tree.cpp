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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        long ans=0;
        
        while(!q.empty())
        {
            int s=q.size();
            long st=q.front().second;
            long end=q.back().second;
            
            for(int i=0;i<s;i++)
            {
                TreeNode *t=q.front().first;
                long in=q.front().second-st;
                q.pop();
                
                if(t->left)
                    q.push({t->left,2*in+1});
                if(t->right)
                    q.push({t->right,2*in+2});
                
            }
            
            ans=max(ans,end-st+1);
        }
        
        return ans;
    }
    
    /*
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        long ans=0;
        
        while(!q.empty())
        {
            int s=q.size();
            long st,end;
            
            for(int i=0;i<s;i++)
            {
                TreeNode *t=q.front().first;
                long in=q.front().second;
                q.pop();
                
                if(i==0)
                    st=in;
                
                if(i==s-1)
                    end=in;
                
                if(t->left)
                    q.push({t->left,2*in+1});
                if(t->right)
                    q.push({t->right,2*in+2});
                
            }
            
            ans=max(ans,end-st+1);
        }
        
        return ans;
    }
    */
};