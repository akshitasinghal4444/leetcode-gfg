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
    Node* insertionSort(struct Node* head)
    {
        //code here
        if(!head || !head->next)
        return head;
        
        Node *t1=head,*t2;
        
        while(t1->next)
        {
            Node *t=t1->next;
            
            if(t->data<=head->data)
            {
                t1->next=t->next;
                t->next=head;
                head=t;
            }
            else
            {
                t2=head;
                
                while(t2->next && t2->next->data<t->data)
                t2=t2->next;
                
                t1->next=t->next;
                t->next=t2->next;
                t2->next=t;
                
                if(t1->next==t)
                t1=t1->next;
            }
        }
        
        return head;
    }
    
};

// { Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
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

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}  // } Driver Code Ends