// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    ll countStrings(int n)
    {
        int m=1e9+7;
        ll e0=1,e1=1;
        
        for(int i=2;i<=n;i++)
        {
            ll n0,n1;
            n1=e0;
            n0=(e0+e1)%m;
            
            e1=n1;
            e0=n0;
        }
        
        return (e1+e0)%m;
    }
	
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends