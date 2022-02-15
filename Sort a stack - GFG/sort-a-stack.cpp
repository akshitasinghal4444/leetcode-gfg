// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   //Your code here
   if(s.size()==0 || s.size()==1)
   return ;
   
   stack<int> s2;
   
   while(!s.empty())
   {
       int x=s.top();
       s.pop();
       
       while(!s2.empty() && s2.top()<x)
       {
           s.push(s2.top());
           s2.pop();
       }
       
       s2.push(x);
   }
   
   while(!s2.empty())
   {
       s.push(s2.top());
       s2.pop();
   }
}

/*
void insert(int x,stack<int> &s)
{
    if(s.empty() || s.top()<=x)
    {
        s.push(x);
        return ;
    }
    
    int y=s.top();
    s.pop();
    insert(x,s);
    s.push(y);
}

void SortedStack :: sort()
{
   //Your code here
   if(s.empty())
   return;
   
   int x=s.top();
   s.pop();
   sort();
   insert(x,s);
}
*/