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
        int pu=find(u,parent);
        int pv=find(v,parent);
        
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
    
    int findCircleNum(vector<vector<int>>& a)
    {
        int i,j,n=a.size();
        int ans=0;
        vector<int> parent(n,-1);
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j])
                    unionByWt(i,j,parent);
            }
        }
        
        for(i=0;i<n;i++)
        {
            if(parent[i]<0)
                ans++;
        }
        
        return ans;
    }
    
    /*
    void bfs(vector<vector<int>>& a,int n,vector<bool> &vis,int in)
    {
        queue<int> q;
        q.push(in);
        vis[in]=1;
        
        while(!q.empty())
        {
            in=q.front();
            q.pop();
            
            for(int i=0;i<n;i++)
            {
                if(a[in][i] && !vis[i])
                {
                    vis[i]=1;
                    q.push(i);
                }
            }
        }  
    }
    
    
    int findCircleNum(vector<vector<int>>& a) {
        int i,n=a.size();
        int ans=0;
        vector<bool> vis(n,0);
        
        for(i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans++;
                bfs(a,n,vis,i);
            }
        }
        
        return ans;
    }
    */
    
    /*
    void dfs(vector<vector<int>>& a,int n,vector<bool> &vis,int in)
    {
        vis[in]=1;
        
        for(int i=0;i<n;i++)
        {
            if(a[in][i] && !vis[i])
                dfs(a,n,vis,i);
        }
    }
    
    int findCircleNum(vector<vector<int>>& a) {
        int i,n=a.size();
        int ans=0;
        vector<bool> vis(n,0);
        
        for(i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(a,n,vis,i);
            }
        }
        
        return ans;
    }
    */
};