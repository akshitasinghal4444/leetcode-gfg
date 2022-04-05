// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{ 
    public:
    
    int bfs(int source,int sink,vector<vector<int>> &g,int n,vector<int> &parent)
    {
        queue<pair<int,int>> q;
        vector<bool> vis(n,0);
        q.push({source, INT_MAX});
        vis[source]=1;
        
        while(!q.empty())
        {
            source=q.front().first;
            int cap=q.front().second;
            q.pop();
            
            for(int i=0;i<n;i++)
            {
                if(g[source][i] && !vis[i])
                {
                    parent[i]=source;
                    
                    if(i==sink)
                        return min(cap,g[source][i]);
                        
                    q.push({i,min(cap,g[source][i])});
                    vis[i]=1;
                }
            }
        }
        return 0;
    }
    
    int ford_fulkerson(int source,int sink,vector<vector<int>> &g,int n)
    {
        int flow=0;
        vector<int> parent(n,-1);
        
        int min_cap;
        while(min_cap=bfs(source,sink,g,n,parent))
        {
            flow+=min_cap;
            
            int u,v=sink;
            while(v!=source)
            {
                u=parent[v];
                g[u][v]-=min_cap;
                g[v][u]+=min_cap;
                v=u;
            }
        }
        
        return flow;
    }
    
    int solve(int n,int m,vector<vector<int>> e)
    {
        vector<vector<int>> g(n+1,vector<int>(n+1,0));
        int i;
        
        for(i=0;i<m;i++)
        {
            g[e[i][0]][e[i][1]]+=e[i][2];
            g[e[i][1]][e[i][0]]+=e[i][2];
        }
        
        return ford_fulkerson(1,n,g,n+1);
    }
    
    /*
    int BFS(vector<vector<int>> &graph,vector<int> &parent,int source,int sink,int N)
   {
       int min_cap=INT_MAX;
       fill(parent.begin(), parent.end(), -1);
       vector<bool> visited(N,false);
       queue<int> q;
       
       q.push(source);
       visited[source]=true;
       parent[source]=-1;
       
       while(q.empty()==false)
       {
           auto u=q.front();
           q.pop();
           
           //adjacents
           
           for(int v=0;v<N;v++)
           {
               if(visited[v]==false && graph[u][v]!=0)
               {
                   if(v==sink)
                   {
                       parent[v]=u;
                       min_cap=min(min_cap,graph[u][v]);
                       return min_cap;
                   }
                   
                   q.push(v);
                   visited[v]=true;
                   min_cap=min(min_cap,graph[u][v]);
                   parent[v]=u;
               }
           }
       }
       
       return 0;
   }
   
   int fordFulkerson(vector<vector<int>> &graph,int source,int sink,int N)
   {
       vector<int> parent(N,-1);
       
       int res=0;
       
       while(BFS(graph,parent,source,sink,N)!=0)
       {
           int min_cap=BFS(graph,parent,source,sink,N);
           
           res+=min_cap;
           
           //considering all the edged in this path.
           
           int v=sink;
           while(v!=source)
           {
               int u=parent[v];
               graph[u][v]-=min_cap;
               graph[v][u]+=min_cap;
               v=parent[v];
           }
       }
       
       return res;
   }
   
   int solve(int N,int M,vector<vector<int>> Edges)
   {
       // code here
       vector<vector<int>> graph;
       
       for(int i=0;i<N;i++)
       {
           vector<int> v1;
           for(int j=0;j<N;j++)
           {
               v1.push_back(0);
           }
           graph.push_back(v1);
       }
       
       for(auto x: Edges)
       {
           int u=x[0]-1;
           int v=x[1]-1;
           int wt=x[2];
           
           graph[u][v]+=wt;
           graph[v][u]+=wt;
       }
       
       return fordFulkerson(graph,0,N-1,N);
       
   }
    */


};



// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int i,j,N,M,u,v,w;
        int res;
        scanf("%d %d",&N,&M);
        vector<vector<int>> Edges; 
        for(i=0;i<M;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
        	Edges.push_back({u,v,w});
    	}
        Solution obj;
        res = obj.solve(N, M, Edges);
        cout<<res<<endl;
    }
    return 0;
}  // } Driver Code Ends