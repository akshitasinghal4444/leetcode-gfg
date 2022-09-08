class Solution {
public:
    bool topo_sort(vector<int> *g,int n,vector<int> &vis,int in)
    {
        if(vis[in]==1)
            return 0;
        
        if(vis[in]==2)
            return 1;
        
        vis[in]=1;
        
        for(auto x:g[in])
        {
            if(!topo_sort(g,n,vis,x))
                return 0;
        }
        
        vis[in]=2;
        return 1;
    }
    
    bool canFinish(int n, vector<vector<int>>& a)
    {
        vector<int> vis(n,0);
        vector<int> g[n];
        
        for(auto v:a)
            g[v[0]].push_back(v[1]);
        
        for(int i=0;i<n;i++)
        {
            if(!topo_sort(g,n,vis,i))
                return 0;
        }
        
        return 1;
    }
    
    /*
    bool canFinish(int n, vector<vector<int>>& a) {
        vector<int> g[n];
        vector<int> in(n,0);
        queue<int> q;
        int i,c=0;
        
        for(auto v:a)
        {
            in[v[1]]++;
            g[v[0]].push_back(v[1]);
        }
        
        for(i=0;i<n;i++)
        {
            if(in[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            i=q.front();
            q.pop();
            c++;
            
            for(int x:g[i])
            {
                in[x]--;
                if(in[x]==0)
                    q.push(x);
            }
        }
        
        return c==n;
    }
    */
};