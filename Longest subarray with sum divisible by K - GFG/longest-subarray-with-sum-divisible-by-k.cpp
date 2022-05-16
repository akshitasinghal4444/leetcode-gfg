// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int a[], int n, int k)
	{
	    // Complete the function
	    unordered_map<int,int> m;
	    int i,ans=0;
	    long long s=0;
	    
	    for(i=0;i<n;i++)
	    {
	        s+=a[i];
	        int x=s%k;
	        
	        if(x<0)
	        x+=k;
	        
	        if(x==0)
	        ans=i+1;
	        else if(m.find(x)!=m.end())
	        ans=max(ans,i-m[x]);
	        else
	        m[x]=i;
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends