class Solution {
public:
    
    int mindis(vector<int> &dis,vector<bool> &vis,int n)
    {
        int mndis=INT_MAX,mnindex=1;
        
        for(int i=1;i<=n;i++)
        {
            if(!vis[i] && dis[i]<mndis)
            {
                mndis=dis[i];
                mnindex=i;
            }
        }
        
        return mnindex;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector<vector<int>> g(n+1,(vector<int>(n+1,INT_MAX)));
        vector<int> dis(n+1,INT_MAX);
        vector<bool> vis(n+1,0);
        
        for(auto v:times)
            g[v[0]][v[1]]=v[2];
        
        dis[k]=0;
        
        int i;
        for(i=0;i<n;i++)
        {
            int u=mindis(dis,vis,n);
            vis[u]=1;
            if(dis[u]==INT_MAX)
                continue;
            
            for(int j=1;j<=n;j++)
            {
                if(!vis[j] && g[u][j]!=INT_MAX && dis[u]+g[u][j]<dis[j])
                    dis[j]=dis[u]+g[u][j];
            }
        }
        
        int mx=INT_MIN;
        for(i=1;i<=n;i++)
        {
            // cout<<i<<":"<<dis[i]<<endl;
            if(dis[i]==INT_MAX)
                return -1;
            
            mx=max(mx,dis[i]);
        }
        
        return mx;
    }
    
    /*
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<pair<int,int>> g[N+1];
        for(int i=0;i<times.size();i++)
            g[times[i][0]].push_back(make_pair(times[i][1],times[i][2]));
        vector<int> dist(N+1, 1e9);
        dist[K] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> q;
        q.push(make_pair(0,K));
        pair<int,int> temp;
        bool visit[N+1];
        memset(visit, false, sizeof(visit));
        while(!q.empty()){
            temp = q.top();
            q.pop();
            int u = temp.second;
            visit[u] = true;
            for(int i=0;i<g[u].size();i++){
                int v = g[u][i].first;
                int weight = g[u][i].second;
                if(visit[v]==false && dist[v] > dist[u] + weight){
                    dist[v] = dist[u] + weight;
                    q.push(make_pair(dist[v], v));
                }
            }
        }
        int ans = 0;
        for(int i=1;i<dist.size();i++){
            ans = max(ans, dist[i]);
        }
        if(ans==1e9) return -1;
        return ans;
    }
    */
};