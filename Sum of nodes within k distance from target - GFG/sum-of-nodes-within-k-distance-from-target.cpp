// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

class Solution{
public:
    unordered_map<Node*,Node*> par;
    int ans=0;
    
    Node* create_parent(Node* root,int t)
    {
        if(!root)
        return NULL;
        
        // cout<<root->data<<":";
        
        if(root->left)
        {
            par[root->left]=root;
            // cout<<root->left->data<<" ";
        }
        
        if(root->right)
        {
            par[root->right]=root;
            // cout<<root->right->data<<" ";
        }
        
        // cout<<endl;
        
        if(root->data==t)
            return root;
        
        Node *x;
        
        if(x=create_parent(root->left,t))
            return x;
            
        return create_parent(root->right,t);
    }
    
    void traverse_down(Node* root,int k)
    {
        if(k<=0 || !root)
        return;
        
        // cout<<root->data<<" ";
        ans+=root->data;
        traverse_down(root->left,k-1);
        traverse_down(root->right,k-1);
    }
    
    void traverse_up(Node* root,int k)
    {
        if(k<=0 || !root)
        return;
        
        if(!par[root])
        {
           return;
        }
        
         ans+=par[root]->data;
            // cout<<par[root]->data<<" ";
        traverse_up(par[root],k-1);
        
        if(par[root]->left && par[root]->left!=root)
        traverse_down(par[root]->left,k-1);
        
        if(par[root]->right && par[root]->right!=root)
        traverse_down(par[root]->right,k-1);
    }
    
    int sum_at_distK(Node* root, int t, int k)
    {
        // code here
        par[root]=NULL;
        Node *x=create_parent(root,t);
        
        ans+=x->data;
        traverse_down(x->left,k);
        // cout<<endl;
        traverse_down(x->right,k);
        // cout<<endl;
        traverse_up(x,k);
        // cout<<endl;
        return ans;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        
        Solution ob;
        cout<< ob.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}

  // } Driver Code Ends