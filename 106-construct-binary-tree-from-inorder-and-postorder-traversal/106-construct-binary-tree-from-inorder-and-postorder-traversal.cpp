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
    unordered_map<int,int> m;
    int j;
    
    TreeNode* build(vector<int>& in, vector<int>& post,int l,int r)
    {
        if(l>r)
            return NULL;
        
        TreeNode *root=new TreeNode(post[j]);
        int mid=m[post[j--]];
        
        root->right=build(in,post,mid+1,r);
        root->left=build(in,post,l,mid-1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int i,n=in.size();
        j=n-1;
        
        for(i=0;i<n;i++)
            m[in[i]]=i;
        
        return build(in,post,0,n-1);
    }
};