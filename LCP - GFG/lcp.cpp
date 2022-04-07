// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string LCP(string a[], int n)
    {
        // code here
        string ans="",s=a[0];
        int i,j;
        
        int l=s.length();
        
        for(i=0;i<l;i++)
        {
            for(j=1;j<n;j++)
            {
                int l1=a[j].length();
                
                if(i>=l1 || s[i]!=a[j][i])
                return (ans.size()>0)?ans:"-1";
            }
            ans+=s[i];
        }
        
        
        return (ans.size()>0)?ans:"-1";
    }
};

// { Driver Code Starts.

int main() 
{

	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        string arr[n];
	        for(int i = 0;i<n;i++)
	            cin>>arr[i];
	        Solution ob;
	        cout<<ob.LCP(arr,n)<<endl;
	    }
	return 0;
}  // } Driver Code Ends