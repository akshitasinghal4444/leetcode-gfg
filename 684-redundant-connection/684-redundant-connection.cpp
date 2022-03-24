class Solution {
public:
    bool dfs(vector<int> *g,int in,vector<bool> &vis,int parent)
    {
        if(vis[in])
            return 0;
        
        vis[in]=1;
        int n=g[in].size();
        int i;
        
        for(i=0;i<n;i++)
        {
            if(g[in][i]!=parent && !dfs(g,g[in][i],vis,in))
                return 0;
        }
        
        return 1;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& e)
    {
        int n=e.size();
        int i;
        vector<int> g[n+1];
        
        for(i=0;i<n;i++)
        {
            vector<bool> vis(n+1,0);
            
            g[e[i][0]].push_back(e[i][1]);
            g[e[i][1]].push_back(e[i][0]);
            
            if(!dfs(g,e[i][0],vis,-1))
                return e[i];
        }
        return {};
    }
    
    /*
    int find(int i,vector<int> &parent)
    {
        if(parent[i]<0)
            return i;
        
        return find(parent[i],parent);
    }
    
    bool union_by_weight(int u,int v,vector<int> &parent)
    {
        int pu=find(u,parent),pv=find(v,parent);
        
        if(pu==pv)
            return 0;
        
        if(parent[pu]<parent[pv])
        {
            parent[pu]+=parent[pv];
            parent[pv]=pu;
        }
        else
        {
            parent[pv]+=parent[pu];
            parent[pu]=pv;
        }
        return 1;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        int n=e.size();
        int i;
        vector<int> parent(n+1,-1);
        
        for(i=0;i<n;i++)
        {
            int u=e[i][0],v=e[i][1];
            
            if(!union_by_weight(u,v,parent))
                return e[i];
        }
        return {};
    }
    */
};