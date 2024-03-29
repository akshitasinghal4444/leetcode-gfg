//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &a) {
        // code here
        if(a[0][0]==0 || a[n-1][m-1]==0)
        return 0;
        
        int i,j,mod=1e9+7;
        vector<vector<long>> dp(n,vector<long>(m,0));
        
        for(i=n-1;i>=0;i--)
        {
            for(j=m-1;j>=0;j--)
            {
                if(a[i][j]==0)
                continue;
                
                if(i==n-1 && j==m-1)
                dp[i][j]=1;
                else if(i==n-1)
                dp[i][j]+=dp[i][j+1];
                else if(j==m-1)
                dp[i][j]+=dp[i+1][j];
                else
                dp[i][j]=(dp[i][j+1]+dp[i+1][j])%mod;
            }
        }
        
        return dp[0][0];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends