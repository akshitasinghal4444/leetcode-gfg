// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int  mod=1e9+7;
    
    long long power(long long k,long long m)
    {
        long long ans=1;
        
        while(m)
        {
            if(m%2!=0)
            ans=(ans*k)%mod;
            
            m=m/2;
            k=(k*k)%mod;
        }
        
        return ans;
    }
    
    long long karyTree(int k, int m) {
        // code here
        return power(k,m);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,m;
        
        cin>>k>>m;

        Solution ob;
        cout << ob.karyTree(k,m) << endl;
    }
    return 0;
}  // } Driver Code Ends