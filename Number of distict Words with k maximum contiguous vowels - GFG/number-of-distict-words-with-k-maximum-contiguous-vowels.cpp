// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
  int m=1000000007;
  
    long find(int n, int k,int v,vector<vector<long>> &dp)
    {
        if(n==0)
        return 1;
        
        if(dp[n][v]==-1)
        {
            long c1=0,c2=0;
            c1=(21*find(n-1,k,k,dp))%m;
            
            if(v)
            c2=(5*find(n-1,k,v-1,dp))%m;
            
            dp[n][v]=(c1+c2)%m;
        }
        
        return dp[n][v];
    }
    
    int kvowelwords(int n, int k) {
        // Write Your Code here
        vector<vector<long>> dp(n+1,vector<long> (k+1,-1));
        return find(n,k,k,dp);
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends