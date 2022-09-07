/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string s;
    
    void preorder(TreeNode* root)
    {
        if(!root)
        {
            s+="n,";
            return;
        }
        
        s+=to_string(root->val);
        s+=",";
        
        preorder(root->left);
        preorder(root->right);
    }
    
    string serialize(TreeNode* root) {
        s="";
        preorder(root);
        return s;
    }

    // Decodes your encoded data to tree.
    int i;
    
    int get(string t,int n)
    {
        string x="";
        
        while(i<n && t[i]!=',')
            x+=t[i++];
        
        i++;
        
        if(x=="n")
            return INT_MAX;
        
        return stoi(x);
    }
    
    TreeNode* deserialize(string t,int n)
    {
        if(i==n)
            return NULL;
        
        int x=get(t,n);
        if(x==INT_MAX) 
            return NULL;
        
        TreeNode *root=new TreeNode(x);
        root->left=deserialize(t,n);
        root->right=deserialize(t,n);
        
        return root;
    }
    
    TreeNode* deserialize(string t) {
        i=0;
        return deserialize(t,t.length());
    }
};

/*
class Codec {
public:

    // Encodes a tree to a single string.
    string s;
    
    void serialize1(TreeNode* root)
    {
        if(!root)
            return;
        
        if(root->left)
            s+=to_string(root->left->val);
        else
            s+='n';
        
        s+=',';
        
        if(root->right)
            s+=to_string(root->right->val);
        else
            s+='n';
        
        s+=',';
        
        serialize1(root->left);
        serialize1(root->right);
    }
    
    string serialize(TreeNode* root) {
        if(!root)
            return "";
        
        s=to_string(root->val);
        s+=',';
        serialize1(root);
        
        return s;
        
    }

    // Decodes your encoded data to tree.
    int i;
    
    int get(string t,int n)
    {
        string x="";
        
        while(i<n && t[i]!=',')
            x+=t[i++];
        
        i++;
        
        if(x=="n")
            return INT_MAX;
        
        return stoi(x);
    }
    
    void deserialize(string t,int n,TreeNode *root)
    {
        if(i==n || !root)
            return ;
        
        int x=get(t,n);
        root->left=(x==INT_MAX)?NULL:new TreeNode(x);
        
        x=get(t,n);
        root->right=(x==INT_MAX)?NULL:new TreeNode(x);
        
        deserialize(t,n,root->left);
        deserialize(t,n,root->right);
        
    }
    
    TreeNode* deserialize(string t) {
        if(t=="")
            return NULL;
        
        i=0;
        int x=get(t,t.length());
        if(x==INT_MAX)
            return NULL;
        
        TreeNode *root=new TreeNode(x);
        deserialize(t,t.length(),root);
        return root;
    }
};
*/

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));