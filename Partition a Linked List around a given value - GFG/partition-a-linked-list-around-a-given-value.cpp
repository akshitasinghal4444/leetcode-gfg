// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    // code here
    Node *t1=new Node(0);
    Node *t2=new Node(0);
    Node *t3=new Node(0);
    
    Node *h1=t1,*h2=t2,*h3=t3;
    
    while(head)
    {
        if(head->data<x)
        {
            t1->next=head;
            t1=t1->next;
        }
        else if(head->data==x)
        {
            t2->next=head;
            t2=t2->next;
        }
        else
        {
            t3->next=head;
            t3=t3->next;
        }
        
        head=head->next;
    }
    
    t3->next=NULL;
    t2->next=h3->next;
    t1->next=h2->next;
    
    return h1->next;
}