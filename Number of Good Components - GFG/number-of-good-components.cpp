//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool dfs(vector<vector<int>>& a,int in,vector<int> &vis,int &n,int edges)
    {
        bool x=a[in].size()==edges;
        
        vis[in]=1;
        n++;
        
        for(int i:a[in])
        {
            if(!vis[i])
            x&=dfs(a,i,vis,n,edges);
        }
        
        return x;
    }
  
    bool good(vector<vector<int>>& a,int in,vector<int> &vis)
    {
        vis[in]=1;
        int edges=a[in].size(),n=1;
        bool x=1;
        
        for(int i:a[in])
        {
            if(!vis[i])
            x&=dfs(a,i,vis,n,edges);
        }
        
        return x & n==edges+1;
    }
  
    int findNumberOfGoodComponent(int v, vector<vector<int>>& a) {
        // code here
        int i,ans=0;
        vector<int> vis(v+1,0);
        
        for(i=1;i<=v;i++)
        {
            if(!vis[i] && good(a,i,vis))
                ans++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends