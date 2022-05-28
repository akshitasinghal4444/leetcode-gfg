// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int maxdis;
    int ans=INT_MAX;
    
    void dfs(int in,vector<vector<int>> &a,int n,int d,vector<bool> &vis)
    {
        vis[in]=1;
        maxdis=max(maxdis,d);
        
        if(d==ans)
        return;
        
        for(auto i:a[in])
        {
            if(!vis[i])
            dfs(i,a,n,d+1,vis);
        }
    }
    
    int partyHouse(int n, vector<vector<int>> &a){
        // code here
        int i,j;
        
        for(i=1;i<=n;i++)
        {
            vector<bool> vis(n+1,0);
 
            maxdis=0;
            dfs(i,a,n,0,vis);
            
            ans=min(ans,maxdis);
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, x, y;
        cin>>N;
        vector<vector<int>> adj(N+1);
        for(int i = 0;i < N-1;i++){
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        Solution ob;
        cout<<ob.partyHouse(N, adj)<<"\n";
    }
    return 0;
}  // } Driver Code Ends