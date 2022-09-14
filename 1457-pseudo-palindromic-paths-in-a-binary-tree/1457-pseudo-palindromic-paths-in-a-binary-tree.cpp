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
    
    unordered_set<int> s;
    int ans;
    
    void find(TreeNode* root)
    {   
        if(!root)
            return;
        
        if(s.find(root->val)==s.end())
            s.insert(root->val);
        else
            s.erase(root->val);
        
        if(!root->left && !root->right)
        {
            if(s.size()<=1)
                ans++;
        }
        else
        {
            find(root->left);
            find(root->right);
        }
        
        if(s.find(root->val)==s.end())
            s.insert(root->val);
        else
            s.erase(root->val);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        ans=0;
        find(root);
        return ans;
    }
    
    /*
    int f[10];
    int ans;
    
    bool check()
    {
        bool single=0;
        
        for(int i=1;i<10;i++)
        {
            if(f[i]%2!=0)
            {
                if(single)
                    return 0;
                single=1;
            }
        }
        
        return 1;
    }
    
    void find(TreeNode* root)
    {   
        if(!root)
            return;
        
        f[root->val]++;
        
        if(!root->left && !root->right)
        {
            if(check())
                ans++;
        }
        else
        {
            find(root->left);
            find(root->right);
        }
        
        f[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        ans=0;
        for(int i=0;i<10;i++)
            f[i]=0;
        
        find(root);
        return ans;
    }
    */
};