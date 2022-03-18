// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minSteps(int A[], int N, int K) {
       sort(A,A+N);
       
       int prefix[N];
       prefix[0] = A[0];
       for(int i = 1; i < N; i++){
           prefix[i] = A[i] + prefix[i-1];
       }
       
       int mn = INT_MAX;
       for(int i = 0; i < N; i++){
           int ub = upper_bound(A+i,A+N,A[i]+K) - A;
           int prev = i > 0 ? prefix[i-1] : 0;
           mn = min(mn,prev + prefix[N-1] - prefix[ub-1] - (A[i]+K)*(N-ub));
       }
       
       return (mn);
   }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin>>N>>K;
        
        int A[N];
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.minSteps(A,N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends