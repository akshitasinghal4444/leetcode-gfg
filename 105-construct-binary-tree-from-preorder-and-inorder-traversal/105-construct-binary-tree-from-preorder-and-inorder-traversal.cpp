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
    
    TreeNode* buildTree(vector<int>& p, vector<int>& i,int pl,int pr,int il,int ir)
    {
        if(pl>pr)
            return NULL;
        
        TreeNode *root=new TreeNode(p[pl]);
        int in=m[p[pl]]-il;
        
        root->left=buildTree(p,i,pl+1,pl+in,il,il+in-1);
        root->right=buildTree(p,i,pl+1+in,pr,il+in+1,ir);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& p, vector<int>& i) {
        
        for(int j=0;j<i.size();j++)
            m[i[j]]=j;
        
        return buildTree(p,i,0,p.size()-1,0,i.size()-1);
    }
};