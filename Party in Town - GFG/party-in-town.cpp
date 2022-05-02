// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int maxdis=INT_MAX;

    int bfs(int u,vector<vector<int>> &a,int n)
    {
        queue<int> q;
        q.push(u);
        
        vector<bool>  vis(n+1,0);
        vis[u]=1;
        int dis=0;
        
        while(!q.empty())
        {
            dis++;
            
            if(dis>maxdis)
            return dis;
            
            int s=q.size();
            
            while(s--)
            {
                u=q.front();
                q.pop();
                
                for(int v:a[u])
                {
                    if(!vis[v])
                    {
                        q.push(v);
                        vis[v]=1;
                    }
                }
            }
            
        }
        
        return dis-1;
    }

    int partyHouse(int n, vector<vector<int>> &a){
        // code here
        int i,j;
        
        for(i=1;i<=n;i++)
        {
            int mx=bfs(i,a,n);
            maxdis=min(maxdis,mx);
        }
        
        return maxdis;
    }

    /*
    int maxdis=INT_MAX;

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
            
            int mx=INT_MIN;
            for(j=1;j<=n;j++)
            {
                if(dis[j]>maxdis)
                {
                    mx=INT_MAX;
                    break;
                }
                
                mx=max(mx,dis[j]);
            }
            
            maxdis=min(maxdis,mx);
        }
        
        return maxdis;
    }
    */
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