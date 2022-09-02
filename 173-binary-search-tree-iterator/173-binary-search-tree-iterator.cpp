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

class BSTIterator {
public:
    
    queue<int> q;
    int n;
    
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        
        inorder(root->left);
        q.push(root->val);
        inorder(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        inorder(root);
        n=q.size();
    }
    
    int next() {
        if(q.empty())
            return -1;
        
        int x=q.front();
        q.pop();
        return x;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/*
class BSTIterator {
public:
    
    vector<int> a;
    int i,n;
    
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        
        inorder(root->left);
        a.push_back(root->val);
        inorder(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        inorder(root);
        i=-1;
        n=a.size();
    }
    
    int next() {
        if(++i>=n)
            return -1;
        
        return a[i];
    }
    
    bool hasNext() {
        return (i+1<n);
    }
};
*/

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */