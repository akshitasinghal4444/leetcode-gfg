// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int minSteps(int a[], int n, int k)
  {
      sort(a,a+n);
      int i;
      
      int p[n];
      p[0]=a[0];
      for(i=1;i<n;i++)
        p[i]=p[i-1]+a[i];
        
        
      int ans=INT_MAX;    
      for(i=0;i<n;i++)
      {
          if(i>0 && a[i]==a[i-1])
          continue;
          
          int prev=(i==0)?0:p[i-1];
          int in=upper_bound(a,a+n,a[i]+k)-a;
          int fwd=(in!=n)?p[n-1]-p[in-1]-(a[i]+k)*(n-in):0;
          
        //   cout<<in<<endl;
          ans=min(ans,prev+fwd);
      }
      return ans;
  }
  
  // 5 3 9 3 6 5 2 7 2
  
  // 0 1 2 3 4 5 6 7 8
  // 2 2 3 3 5 5 6 7 9
  


  
  /*
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
   */
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