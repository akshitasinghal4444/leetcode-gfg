class Solution {
public:
    vector<int> ans;
    
    bool topo_sort(vector<int> *g,int in,vector<int> &vis)
    {
        vis[in]=1;
        int n=g[in].size();
        
        for(int i=0;i<n;i++)
        {
            if(vis[g[in][i]]==1)
                return 0;
            if(vis[g[in][i]]==0 && !topo_sort(g,g[in][i],vis))
                return 0;
        }
        
        ans.push_back(in);
        vis[in]=2;
        
        return 1;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& a)
    {
        vector<int> g[n];
        vector<int> vis(n,0);
        
        int i;
        ans={};
        
        for(auto v:a)
            g[v[0]].push_back(v[1]);
        
        for(i=0;i<n;i++)
        {
            if(vis[i]==0 && !topo_sort(g,i,vis))
                return {};
        }
        
        return ans;
    }
    
    /*
    vector<int> ans;
    
    bool topo_sort(vector<int> *g,int in,vector<int> &vis)
    {
        vis[in]=1;
        int n=g[in].size();
        
        for(int i=0;i<n;i++)
        {
            if(vis[g[in][i]]==1)
                return 0;
            if(vis[g[in][i]]==0 && !topo_sort(g,g[in][i],vis))
                return 0;
        }
        
        ans.push_back(in);
        vis[in]=2;
        
        return 1;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& a)
    {
        vector<int> g[n];
        vector<int> vis(n,0);
        
        int i;
        ans={};
        
        for(auto v:a)
            g[v[1]].push_back(v[0]);
        
        for(i=0;i<n;i++)
        {
            if(vis[i]==0 && !topo_sort(g,i,vis))
                return {};
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    */
};