// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 
#define m 1000000007
class Solution{
  public:
    
    int fun(string &s)
    {
        int a=0,b=0,c=0;
        int n,i;
        n=s.length();
        
        for(i=0;i<n;i++)
        {
            if(s[i]=='a')
            a=((2*a)%m+1)%m;
            else if(s[i]=='b')
            b=((2*b)%m+a)%m;
            else if(s[i]=='c')
            c=((2*c)%m+b)%m;
        }
        return c;
    }

};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends