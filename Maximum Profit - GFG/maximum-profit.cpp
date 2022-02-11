// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int maxProfit(int k ,int n, int a[])
  {
      if(k==0 || n==0)
      return 0;
      
      vector<vector<int>> dp(k+1,vector<int>(n));
      
      int i,j;
      
      for(i=0;i<=k;i++)
      {
          int mx=INT_MIN;
          for(j=0;j<n;j++)
          {
              if(i==0 || j==0)
              dp[i][j]=0;
              else 
              {
                  mx=max(mx,dp[i-1][j-1]-a[j-1]);
                  dp[i][j]=max(dp[i][j-1],a[j]+mx);
              }
          }
      }
      return dp[k][n-1];
  }
  
  /*
  int maxProfit(int k ,int n, int a[])
  {
      int i,j;
      int dp[k+1][n];
      for(i=0;i<=k;i++)
      {
          int mx=INT_MIN;
          for(j=0;j<n;j++)
          {
              if(i==0 || j==0)
              dp[i][j]=0;
              else
              {
                  mx=max(mx,dp[i-1][j-1]-a[j-1]);
                  dp[i][j]=max(dp[i][j-1],mx+a[j]);
              }
          }
      }
      return dp[k][n-1];
  }
  */
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends