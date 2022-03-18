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
            s+='n';
            s+=',';
            return ;
        } 
        
        s+=to_string(root->val);
        s+=',';
        
        preorder(root->left);
        preorder(root->right);
    }
    
    string serialize(TreeNode* root) {
        
        if(!root)
            return "";
        
        s="";
        preorder(root);
        
        return s;
    }

    // Decodes your encoded data to tree.
    int i;
    
    TreeNode* deserialize(string s,int n)
    {
        string t="";
        for(i;i<n;i++)
        {
            if(s[i]==',')
                break;
            
            t+=s[i];
        }
        i++;
        
        if(t=="n")
            return NULL;
        
        TreeNode *root=new TreeNode(stoi(t));
        root->left=deserialize(s,n);
        root->right=deserialize(s,n);
        
        return root;
    }
    
    TreeNode* deserialize(string s) {
        
        if(s.size()==0)
            return NULL;
        
        int n=s.size();  
        i=0;
        return deserialize(s,n);
    }
};

/*
class Codec {
public:
    
    void serialize(TreeNode* root,string &s)
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
        
        serialize(root->left,s);
        serialize(root->right,s);
    }
    
    int j;
    void deserialize(string s,int n,TreeNode *root)
    {
        if(!root)
            return;
        
        string t="";
        for(j;j<n;j++)
        {
            if(s[j]==',')
                break;
            
            t+=s[j];
        }
        
        if(t!="n" && t.size()>0)
        root->left=new TreeNode(stoi(t));
        
        t="";
        for(j=j+1;j<n;j++)
        {
            if(s[j]==',')
                break;
            
            t+=s[j];
        }
        j++;
        
        if(t!="n" && t.size()>0)
        root->right=new TreeNode(stoi(t));
        
        
        deserialize(s,n,root->left);
        deserialize(s,n,root->right);
        
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";
        
        string s=to_string(root->val);
        s+=',';
        serialize(root,s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        
        if(s.size()==0)
            return NULL;
        
        int i,n=s.size();
        string t="";
        
        for(i=0;i<n;i++)
        {
            if(s[i]==',')
                break;
            
            t+=s[i];
        }
        
        TreeNode *root=new TreeNode(stoi(t));
        j=i+1;
        deserialize(s,n,root);
        
        return root;
    }
};
*/


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));