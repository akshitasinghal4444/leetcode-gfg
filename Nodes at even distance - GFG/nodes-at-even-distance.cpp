// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    void dfs(vector<int> *g,int in,int &even,int &odd,int level,int par,vector<bool> &vis)
    {
        vis[in]=1;
        
        if(level%2==0)
        even++;
        else
        odd++;
        
        int n=g[in].size(),i;
        // cout<<in<<":";
        
        for(i=0;i<n;i++)
        {
            // cout<<g[in][i]<<" ";
            if(!vis[g[in][i]] && g[in][i]!=par)
            dfs(g,g[in][i],even,odd,level+1,in,vis);
        }
        // cout<<endl;
    }
    
    int countOfNodes(vector<int> g[], int n)
    {
        // code here
        int i,ans=0;
        vector<bool> vis(n,0);
        for(i=0;i<=n;i++)
        {
            if(vis[i])
            continue;
            
            int even=0,odd=0;
            
            dfs(g,i,even,odd,0,-1,vis);
            
            if(even>0)
            ans+=(even*(even-1)/2);
            
            if(odd>0)
            ans+=(odd*(odd-1)/2);
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>graph[n+1];
        for(int i=0;i<n-1;i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        Solution ob;
        cout<<ob.countOfNodes(graph, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends