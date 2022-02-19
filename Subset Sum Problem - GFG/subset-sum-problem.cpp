// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool isSubsetSum(int n ,int a[], int s)
    {
        bool dp[n+1][s+1];
        int i,j;
        
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=s;j++)
            {
                if(j==0)
                dp[i][j]=1;
                else if(i==0)
                dp[i][j]=0;
                else if(a[i-1]<=j)
                dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i-1]];
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][s];
    }

/*
    bool isSubsetSum(int n ,int a[], int sum){
        // code here 
        bool dp[n+1][sum+1];
        int i,j;
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=sum;j++)
            {
                if(j==0)
                dp[i][j]=1;
                else if(i==0)
                dp[i][j]=0;
                else if(a[i-1]>j)
                dp[i][j]=dp[i-1][j];
                else
                dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]];
            }
        }
        return dp[n][sum];
    }
*/
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends