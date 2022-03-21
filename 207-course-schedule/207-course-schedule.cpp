class Solution {
public:
    
    bool topo_sort(vector<int> *g,int in,vector<int> &vis)
    {
        int n=g[in].size();
        vis[in]=1;
        
        for(int i=0;i<n;i++)
        {
            if(vis[g[in][i]]==1)
                return 0;
            
            if(vis[g[in][i]]==0 && !topo_sort(g,g[in][i],vis))
                return 0;
        }
        
        vis[in]=2;
        return 1;
    }
    
    bool canFinish(int n, vector<vector<int>>& a) {
        vector<int> g[n];
        vector<int> vis(n,0);
        int i;
        
        for(i=0;i<a.size();i++)
            g[a[i][1]].push_back(a[i][0]);
        
        for(i=0;i<n;i++)
        {
            if(vis[i]!=2 && !topo_sort(g,i,vis))
                return 0;
        }
            
        return 1;
    }
};