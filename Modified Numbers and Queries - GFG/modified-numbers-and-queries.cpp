//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
  
    void fill(vector<long> &dp,int n)
    {
        int i,j;
        
        for(i=2;i<=n;i++)
        {
            if(dp[i]!=0)
            continue;
            
            for(j=i;j<=n;j+=i)
            dp[j]+=i;
        }
    }
  
    int sumOfAll(int l, int r){
        // code here
        vector<long> dp(r+1,0);
        int ans=0;
        
        fill(dp,r);
        
        while(l<=r)
        ans+=dp[l++];
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin>>l>>r;
        Solution ob;
        cout<<ob.sumOfAll(l,r)<<endl;
    }
    return 0;
}

// } Driver Code Ends