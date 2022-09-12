class Solution {
public:
    int find(int u,vector<int> &parent)
    {
        if(parent[u]<0)
            return u;
        
        return parent[u]=find(parent[u],parent);
    }
    
    void unionByWt(int u,int v,vector<int> &parent)
    {
        int pu=find(u,parent),pv=find(v,parent);
        
        if(pu==pv)
            return;
        
        if(parent[pu]<=parent[pv])
        {
            parent[pu]+=parent[pv];
            parent[pv]=pu;
        }
        else
        {
            parent[pv]+=parent[pu];
            parent[pu]=pv;
        }
    }
    
    int removeStones(vector<vector<int>>& a)
    {
        int i,j,n=a.size();
        int ans=0;
        vector<int> parent(n,-1);
        unordered_map<int,vector<int>> row,col;
        
        for(i=0;i<n;i++)
        {
            row[a[i][0]].push_back(i);
            col[a[i][1]].push_back(i);
        }
        
        for(i=0;i<n;i++)
        {
            for(int x:row[a[i][0]])
                unionByWt(x,i,parent);
            
            for(int x:col[a[i][1]])
                unionByWt(x,i,parent);
        }
        
        for(i=0;i<n;i++)
        {
            if(parent[i]<0)
                ans+=abs(parent[i])-1;
        }
        
        return ans;
    }
    
    /*
    void dfs(vector<vector<int>>& a,int n,vector<bool> &vis,int in,int &c)
    {
        if(vis[in])
            return;
        
        vis[in]=1;
        c++;
        
        for(int i=0;i<n;i++)
        {
            if(i!=in && !vis[i] && a[i][0]==a[in][0] || a[i][1]==a[in][1])
                dfs(a,n,vis,i,c);
        }
        
    }
    
    int removeStones(vector<vector<int>>& a) {
        int i,j,n=a.size();
        int ans=0;
        vector<bool> vis(n,0);
        
        for(i=0;i<n;i++)
        {
            if(!vis[i])
            {
                int c=0;
                dfs(a,n,vis,i,c);
                ans+=c-1;
            }
        }
        
        return ans;      
    }
    */
    
    /*
    void dfs(vector<int> *g,int n,vector<bool> &vis,int in,int &c)
    {
        if(vis[in])
            return;
        
        vis[in]=1;
        c++;
        
        for(int x:g[in])
            dfs(g,n,vis,x,c);
        
    }
    
    int removeStones(vector<vector<int>>& a) {
        int i,j,n=a.size();
        int ans=0;
        vector<int> g[n];
        vector<bool> vis(n,0);
        
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {   
                if(a[i][0]==a[j][0] || a[i][1]==a[j][1])
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }                   
            }
        }
        
        for(i=0;i<n;i++)
        {
            if(!vis[i])
            {
                int c=0;
                dfs(g,n,vis,i,c);
                ans+=c-1;
            }
        }
        
        return ans;
        
    }
    */
};