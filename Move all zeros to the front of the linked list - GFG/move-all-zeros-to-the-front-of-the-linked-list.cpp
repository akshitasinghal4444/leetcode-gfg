// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node **head_ref, int new_data) {
    struct Node *new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void moveZeroes(struct Node **head);

// function to displaying nodes
void display(struct Node *head) {
    while (head != NULL) {
	    cout << head->data << " ";
	    head = head->next;
    }
    cout <<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int q;
        struct Node *Head=NULL;
        for(int i=0;i<n;i++)
        {
            cin>>q;
            push(&Head,q);
        }
        moveZeroes(&Head);
        display(Head);

    }
}
// } Driver Code Ends


//User function Template for C

/* Linked List Node structure
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

// Move Zeros to the front of the list
void moveZeroes(struct Node **head)
{
    //Your code here
    Node *h1=*head,*h2=new Node(0),*h3;
    h3=h2;
    
    while(h1 && h1->data==0)
        h1=h1->next;
        
    if(!h1)
    return ;
    
    while(h1->next)
    {
        if(h1->next->data==0)
        {
            h2->next=h1->next;
            h2=h2->next;
            
            h1->next=h1->next->next;
        }
        else
        h1=h1->next;
    }
    
    h2->next=*head;
    *head=h3->next;
}