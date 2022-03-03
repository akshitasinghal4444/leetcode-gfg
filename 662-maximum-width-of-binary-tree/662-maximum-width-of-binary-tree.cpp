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
    int widthOfBinaryTree(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int ans=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        while(!q.empty())
        {
            int s=q.size();
            int st=q.front().second,end=q.back().second;
            ans=max(ans,end-st+1);
            
            while(s--)
            {
                root=q.front().first;
                long i=q.front().second-st;
                q.pop();
                
                if(root->left)
                    q.push({root->left,2*i+1});
                
                if(root->right)
                    q.push({root->right,2*i+2});
            }
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