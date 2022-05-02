// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int maxdis=INT_MAX;
    int ans;
    
    void dfs(int u,vector<int> &dis,vector<vector<int>> &a)
    {
        if(dis[u]==maxdis)
        return;
        
        for(int v:a[u])
        {
            if(dis[v]==INT_MAX)
            {
                dis[v]=dis[u]+1;
                dfs(v,dis,a);
            }
        }
    }

    int partyHouse(int n, vector<vector<int>> &a){
        // code here
        int i,j;
        
        for(i=1;i<=n;i++)
        {
            vector<int> dis(n+1,INT_MAX);
            dis[i]=0;
            dfs(i,dis,a);
            
            // cout<<i<<":";
            int mx=INT_MIN;
            for(j=1;j<=n;j++)
            {
                // cout<<dis[j]<<",";
                if(dis[j]>maxdis)
                {
                    mx=INT_MAX;
                    break;
                }
                
                mx=max(mx,dis[j]);
            }
            
            // cout<<" "<<mx<<endl;
            if(mx<maxdis)
            {
                maxdis=mx;
                // ans=i;
            }
        }
        
        return maxdis;
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