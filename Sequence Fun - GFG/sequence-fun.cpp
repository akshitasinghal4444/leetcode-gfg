//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
	public:
	
		int NthTerm(int n){
		    // Code  here
		    if(n==1)
		    return 2;
		    
		    int i,m=1e9+7;
		    long ans=2;
		    
		    for(i=2;i<=n;i++)
		    {
		        ans=((ans*i)+1)%m;
		    }
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends