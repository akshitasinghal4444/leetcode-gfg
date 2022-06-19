// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* reverseBetween(Node* head, int m, int n)
   {
       //code here
       Node* s=head;Node* e=head;Node* beforestart=NULL;
       //find(s,e,m,n,beforestart);
       int c=1;
       
       while(s!=NULL && c<m){
         beforestart=s;
          s=s->next;
          c++;
       }
       c=1;
       while(e!=NULL && c<n){
          e=e->next;
          c++;
       }
       Node* front=s;
       Node* curr=NULL;
       Node* prev=NULL;
       //cout<<s->data<<"\n"<<e->data<<"\n";
       while(front!=NULL&& curr!=e){
           curr=front;
           front=front->next;
           curr->next=prev;
           prev=curr;
       }
       
       if(beforestart!=NULL){
           beforestart->next=curr;
           
       }
       s->next=front;
       if(m==1){
           return e;
       }
       if(m>=2){
           return head;
       }
       
       
       
   }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends