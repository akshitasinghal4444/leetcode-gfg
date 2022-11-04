//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string baseEquiv(int n, int m){
        // code here
        int l=2,h=32;
        
        while(l<=h)
        {
            int mid=(l+h)/2;
            int x=log(n)/log(mid)+1;
            
            if(x==m)
            return "Yes";
            
            if(x<m)
            h=mid-1;
            else
            l=mid+1;
        }
        
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        cout<<ob.baseEquiv(n,m)<<endl;
    }
    return 0;
}

// } Driver Code Ends