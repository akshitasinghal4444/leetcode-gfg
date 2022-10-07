class Solution {
    
public:
    
    vector<vector<int>> ans;
    vector<int> t;
    
    void dfs(vector<vector<int>>& g,int in,int n)
    {

        t.push_back(in);
        
        if(in==n-1)
        {
            ans.push_back(t);
            t.pop_back();
            return;
        }
        
        for(int i:g[in])
            dfs(g,i,n);
        
        t.pop_back();
            
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        int n=g.size();
        
        dfs(g,0,n);
        
        return ans;
    }
    
    /*
    vector<vector<int>> ans;
    vector<int> t;
    
    void dfs(vector<vector<int>>& g,int in,int n,vector<bool> &vis)
    {
        if(vis[in])
            return;
        
        vis[in]=1;
        t.push_back(in);
        
        if(in==n-1)
        {
            ans.push_back(t);
            vis[in]=0;
            t.pop_back();
            return;
        }
        
        for(int i:g[in])
            dfs(g,i,n,vis);
        
        vis[in]=0;
        t.pop_back();
            
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        int n=g.size();
        vector<bool> vis(n,0);
        
        dfs(g,0,n,vis);
        
        return ans;
    }
    */
};