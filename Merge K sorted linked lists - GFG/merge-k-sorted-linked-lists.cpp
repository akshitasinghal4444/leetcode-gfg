// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* merge(Node *a,Node *b)
    {
        if(!a)
        return b;
        if(!b)
        return a;
        
        Node *h,*t;
        
        if(a->data<=b->data)
        {
            t=a;
            a=a->next;
        }
        else
        {
            t=b;
            b=b->next;
        }
        
        h=t;
        
        while(a && b)
        {
            if(a->data<=b->data)
            {
                t->next=a;
                a=a->next;
            }
            else
            {
                t->next=b;
                b=b->next;
            }
            t=t->next;
        }
        
        if(!a)
        t->next=b;
        else
        t->next=a;
        
        return h;
    }
    
    Node * mergeKLists(Node *a[], int k)
    {
           // Your code here
           Node *ans=NULL;
           int i;
           
           for(i=0;i<k;i++)
           ans=merge(ans,a[i]);
           
           return ans;
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends