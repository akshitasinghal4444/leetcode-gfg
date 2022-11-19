//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

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
//User function Template for C++

class Solution{
    public:
    bool areAnagrams(Node *r1, Node *r2)
    {
        if(!r1 && !r2)
        return 1;
        
        if(!r1 || !r2)
        return 0;
        
        queue<Node *> q1,q2;
        
        q1.push(r1);
        q2.push(r2);
        
        while(!q1.empty() && !q2.empty())
        {
            int s1=q1.size();
            int s2=q2.size();
            unordered_map<int,int> m1,m2;
            
            while(s1--)
            {
                r1=q1.front();
                q1.pop();
                
                m1[r1->data]++;
                
                if(r1->left)
                q1.push(r1->left);
                
                if(r1->right)
                q1.push(r1->right);
            }
            
            while(s2--)
            {
                r2=q2.front();
                q2.pop();
                
                m2[r2->data]++;
                
                if(r2->left)
                q2.push(r2->left);
                
                if(r2->right)
                q2.push(r2->right);
            }
            
            if(m1!=m2)
            return 0;
        }
        
        if(q1.size() || q2.size())
        return 0;
        
        return 1;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}

// } Driver Code Ends