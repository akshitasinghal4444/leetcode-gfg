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
    
    TreeNode *bst(vector<int>& pre,int l,int r)
    {
        if(l>r)
            return NULL;
        
        TreeNode *root=new TreeNode(pre[j]);
        int mid=m[pre[j++]];
        
        root->left=bst(pre,l,mid-1);
        root->right=bst(pre,mid+1,r);
        
        return root;
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& pre) {
        j=0;
        
        vector<int> in=pre;
        sort(in.begin(),in.end());
        
        int n=in.size();
        for(int i=0;i<n;i++)
            m[in[i]]=i;
        
        return bst(pre,0,n-1);
    }
};