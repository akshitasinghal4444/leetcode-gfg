class Solution {
public:
    vector<int> ans;
    
    bool dfs(vector<int> *g,int n,vector<int> &vis,int in)
    {
        vis[in]=1;
        
        for(int x:g[in])
        {
            if(!vis[x] && !dfs(g,n,vis,x))
                return 0;
            
            if(vis[x]==1)
                return 0;
        }
        
        ans.push_back(in);
        vis[in]=2;
        
        return 1;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& a) {
        vector<int> g[n];
        vector<int> vis(n,0);
        
        for(auto v:a)
            g[v[1]].push_back(v[0]);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i] && !dfs(g,n,vis,i))
                return {};
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};