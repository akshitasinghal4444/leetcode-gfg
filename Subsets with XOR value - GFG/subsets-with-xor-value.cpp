// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
public:

    int subsets(int i,int n,vector<int> a,int k,int x,vector<vector<int>> &dp)
    {
        if(i==n)
        {
            if(x==k)
            return 1;
            else
            return 0;
        }
        
        if(dp[i][x]==-1)
        dp[i][x]=subsets(i+1,n,a,k,x,dp)+subsets(i+1,n,a,k,x^a[i],dp);
        
        return dp[i][x];
    }
    
    int subsetXOR(vector<int> a, int n, int k) {
        // code here
        int xn=*max_element(a.begin(),a.end());
        xn=ceil(log2(xn))+1;
        xn=(1<<xn)-1;
        // cout<<xn<<endl;
        vector<vector<int>> dp(n,vector<int>(xn,-1));
        
        return subsets(0,n,a,k,0,dp);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}  // } Driver Code Ends