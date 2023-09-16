//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        // your code here
        if(n<=2)
        return n;
        
        if(n==3)
        return 4;
        
        long long n1=4,n2=2,n3=1,m=1000000007;
        
        for(int i=4;i<=n;i++)
        {
            long long x=(n1+n2+n3)%m;
            n3=n2;
            n2=n1;
            n1=x;
        }
        
        return n1;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends