// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    Node * findParent(Node* root,unordered_map<Node*,Node*> &p, int t)
    {
        if(!root)
        return NULL;
        
        if(root->data==t)
        return root;
        
        bool f=0;
        Node *tar;
        
        if(root->left)
        {
            p[root->left]=root;
            if(root->left->data==t)
            {
                f=1;
                tar=root->left;
            }
            
        }
            
            
        if(root->right)
        {
            p[root->right]=root;
            if(root->right->data==t)
            {
                f=1;
                tar=root->right;
            }   
        }
            
        if(f==0)
        {
            tar=findParent(root->left,p,t); 
            
            if(tar==NULL)
            tar=findParent(root->right,p,t);
            else
            Node *x=findParent(root->right,p,t);
        }
        
        return tar;
    }
  
    int minTime(Node* root, int t) 
    {
        // Your code goes here
        unordered_map<Node*,Node*> parent;
        unordered_set<Node*> vis;
        queue<Node*> q;
        int ans=0;
        
        Node* t1,*t2;
        t1=findParent(root,parent,t);
            
        q.push(t1);
        vis.insert(t1);
        
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                t2=q.front();
                q.pop();
                
                if(t2->left && vis.find(t2->left)==vis.end())
                {
                    vis.insert(t2->left);
                    q.push(t2->left);
                    
                }
                
                if(t2->right && vis.find(t2->right)==vis.end())
                {
                    vis.insert(t2->right);
                    q.push(t2->right);
                    
                }
                
                if(parent.find(t2)!=parent.end() && vis.find(parent[t2])==vis.end())
                {
                    vis.insert(parent[t2]);
                    q.push(parent[t2]);
                }
            }
            ans++;
        }
        return ans-1;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends