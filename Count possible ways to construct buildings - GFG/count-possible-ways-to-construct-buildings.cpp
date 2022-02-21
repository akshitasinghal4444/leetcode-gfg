// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int m=1e9+7;
	
	int TotalWays(int n)
	{
	    long p=1,s=1;
	    for(int i=2;i<=n;i++)
	    {
	        long np,ns;
	        np=s;
	        ns=(p+s)%m;
	        
	        p=np;
	        s=ns;
	    }
	    
	    s=(s+p)%m;
	    return (s*s)%m;
	    
	}
	
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends