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
    int i;
    unordered_map<int,int> m;
    
    
    TreeNode* helper(vector<int>& p,vector<int>& in,int l,int r)
    {
        if(l>r)
            return NULL;
        
        TreeNode* root=new TreeNode(p[i]);
        int mid=m[p[i]];
        i++;
        
        root->left=helper(p,in,l,mid-1);
        root->right=helper(p,in,mid+1,r);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& p) {
        
        vector<int> in(p.begin(),p.end());
        sort(in.begin(),in.end());
        
        for(int i=0;i<in.size();i++)
            m[in[i]]=i;
            
        i=0;
    
        return helper(p,in,0,in.size()-1);
    }
};