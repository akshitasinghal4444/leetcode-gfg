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
    int j;
    unordered_map<int,int> m;
    
    TreeNode* build(vector<int>& pre, vector<int>& in,int l,int r)
    {
        if(l>r)
            return NULL;
        
        TreeNode *root=new TreeNode(pre[j]);
        int mid=m[pre[j++]];
        
        root->left=build(pre,in,l,mid-1);
        root->right=build(pre,in,mid+1,r);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        j=0;
        int i,n=in.size();
        
        for(i=0;i<n;i++)
            m[in[i]]=i;
        
        return build(pre,in,0,n-1);        
    }
    
    /*
    int j;
    
    int find(vector<int> &in,int n,int l,int r)
    {
        while(l<=r)
        {
            if(in[l]==n)
                return l;
            
            l++;
        }
        
        return -1;
    }
    
    TreeNode* build(vector<int>& pre, vector<int>& in,int l,int r)
    {
        if(l>r)
            return NULL;
        
        TreeNode *root=new TreeNode(pre[j]);
        int mid=find(in,pre[j++],l,r);
        
        root->left=build(pre,in,l,mid-1);
        root->right=build(pre,in,mid+1,r);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        j=0;
        return build(pre,in,0,in.size()-1);        
    }
    */
};