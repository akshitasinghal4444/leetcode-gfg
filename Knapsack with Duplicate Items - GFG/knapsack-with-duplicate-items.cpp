// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int n, int wt, int val[], int w[])
    {
        // code here
        vector<int> dp(wt+1,0);
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=1;j<=wt;j++)
            {
                if(w[i]<=j)
                dp[j]=max(dp[j],val[i]+dp[j-w[i]]);
            }
        }
        return dp[wt];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends