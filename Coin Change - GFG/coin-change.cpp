// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int count(int a[], int m, int n) {

        // code here.
        vector<long long int> dp(n+1,0);
        dp[0]=1;
        int i,j;
        
        for(i=0;i<m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(a[i]<=j)
                dp[j]+=dp[j-a[i]];
            }
        }
        
        return dp[n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends