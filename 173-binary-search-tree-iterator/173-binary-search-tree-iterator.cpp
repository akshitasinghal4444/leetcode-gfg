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
    TreeNode *head,*t; 
    
    void convert(TreeNode* root)
    {
        if(!root)
            return;
        
        convert(root->left);
        
        t->right=root;
        t=t->right;
        
        convert(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        
        head=new TreeNode(0);
        t=head;
        convert(root);
    }
    
    int next() {
        head=head->right;
        return head->val;
    }
    
    bool hasNext() {
        return (head->right!=NULL);
    }
};


/*
class BSTIterator {
public:
    stack<TreeNode*> st;
    
    BSTIterator(TreeNode* root) {
        st.push(root);
        
        while(root->left)
        {
            st.push(root->left);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode *root=st.top();
        st.pop();
        
        int ans=root->val;
        
        if(root->right)
        {
            root=root->right;
            st.push(root);
            while(root->left)
            {
                st.push(root->left);
                root=root->left;
            }
        }
        
        return ans;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
*/

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */