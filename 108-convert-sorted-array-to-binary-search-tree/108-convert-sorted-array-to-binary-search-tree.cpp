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
    TreeNode* ToBST(vector<int>& a,int l,int r)
    {
        if(l<=r)
        {
            int mid=(l+r)/2;
            TreeNode *root=new TreeNode(a[mid]);
            root->left=ToBST(a,l,mid-1);
            root->right=ToBST(a,mid+1,r);
            
            return root;
        }
        return NULL;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& a) {
        return ToBST(a,0,a.size()-1);
    }
};