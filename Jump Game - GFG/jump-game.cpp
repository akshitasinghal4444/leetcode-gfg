// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int arr[], int n) {
       int maxi = 0, cur = 0;
       for(int i=0; i<n-1; i++) {
           maxi = max(maxi, arr[i]+i);
           if(i == cur) {
               cur = maxi;
           }
       }
       if(cur < n-1) {
           return 0;
       }
       return 1;
   }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends