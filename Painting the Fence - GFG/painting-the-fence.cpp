// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        
        if(n==1)
        return k;
        
        int m=1e9+7;
        
        long same=0,diff=k;
        
        while(--n)
        {
            int ns,nd;
            ns=diff;
            nd=(((same+diff)%m)*(k-1))%m;
            
            same=ns;
            diff=nd;
        }
        return (same+diff)%m;
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends