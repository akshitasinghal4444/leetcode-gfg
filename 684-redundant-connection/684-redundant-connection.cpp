class Solution {
public:
    
//     void remove_leaves(unordered_map<int,unordered_set<int>> &graph)
//     {
//         int n = graph.size();
//     vector<int> remove = {};
//     for (auto& kv : graph) {
//       int node = kv.first;
//       auto& adjlist = kv.second;
//       if (adjlist.size() == 1) { // leaf node
//         remove.push_back(node);
//         auto it = adjlist.begin();
//         graph[*it].erase(node);
//       }
//     }

//     if (remove.empty()) return;
//     else {
//       for (int node : remove) graph.erase(node);
//       remove_leaves(graph);
//     }
//     }
        

    
    void remove_leaves(unordered_map<int,unordered_set<int>> &g)
    {
        int i,n=g.size();
        vector<int> leaf;
        
        for(auto it:g)
        {
            int i=it.first;
            if(g[i].size()==1)
            {
                auto it=g[i].begin();
                g[(*it)].erase(i);
                leaf.push_back(i);  
            }
        }
        
        n=leaf.size();
        for(i=0;i<n;i++)
        {
            g.erase(leaf[i]);
        }
        
        if(n>0)
            remove_leaves(g);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& e)
    {
        int n=e.size();
        int i;
        unordered_map<int,unordered_set<int>> g;
        
        for(i=0;i<n;i++)
        {
            g[e[i][0]].insert(e[i][1]);
            g[e[i][1]].insert(e[i][0]);
        }
        
        remove_leaves(g);
        
        for(i=n-1;i>=0;i--)
        {
            if(g.find(e[i][0])!=g.end() && g.find(e[i][1])!=g.end())
                return e[i];
        }
        
        return {};
    }
    
    /*
    int find(int i,vector<int> &parent)
    {
        if(parent[i]<0)
            return i;
        
        parent[i]=find(parent[i],parent);
        return parent[i];
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
    
    /*
    unordered_set<int> cycle;
    int start=-1;
    
    void dfs(vector<int> *g,vector<bool> &vis,int in,int parent)
    {
        if(vis[in])
        {
            cycle.insert(in);
            start=in;
            return;
        }
        
        vis[in]=1;
        int i,n=g[in].size();
        
        for(i=0;i<n;i++)
        {
            if(g[in][i]==parent)
                continue;
            
            if(cycle.empty())
                dfs(g,vis,g[in][i],in);
            
            if(in==start)
            {
                start=-1;
                return;
            }
            
            if(start!=-1)
                cycle.insert(in);
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& e)
    {
        int n=e.size();
        int i;
        vector<int> g[n+1];
        vector<bool> vis(n+1,0);
        
        for(i=0;i<n;i++)
        {
            g[e[i][0]].push_back(e[i][1]);
            g[e[i][1]].push_back(e[i][0]);
        }
        
        dfs(g,vis,1,-1);
        
        for(i=n-1;i>=0;i--)
        {
            if(cycle.find(e[i][0])!=cycle.end() && cycle.find(e[i][1])!=cycle.end())
                return e[i];
        }
        
        return {};
    }
    */
    
    /*
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
    */
    
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
    
    //archit91

};