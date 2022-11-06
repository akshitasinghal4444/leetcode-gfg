//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int t)
    {
        // code here
        vector<int> a={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        int i,j,n=10;
        vector<vector<int>> dp(t+1);
        dp[0]={};
        
        for(j=1;j<=t;j++)
        {
            for(i=0;i<n;i++)
            {
                if(j==a[i])
                    dp[j]={j};
                else if(j>a[i] && dp[j-a[i]].size()>0 &&(dp[j].size()==0 || (dp[j-a[i]].size()+1)<dp[j].size()))
                {
                    dp[j]=dp[j-a[i]];
                    dp[j].push_back(a[i]);
                }
            }
        }
        
        return dp[t];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends