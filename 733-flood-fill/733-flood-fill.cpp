class Solution {
public:
    void dfs(vector<vector<int>>& g,int m,int n,int sr,int sc,int nc,int oc)
    {
        if(sr<0 || sc<0 || sr>=m || sc>=n || g[sr][sc]!=oc)
            return;
        
        g[sr][sc]=nc;
        
        dfs(g,m,n,sr-1,sc,nc,oc);
        dfs(g,m,n,sr+1,sc,nc,oc);
        dfs(g,m,n,sr,sc-1,nc,oc);
        dfs(g,m,n,sr,sc+1,nc,oc);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& g, int sr, int sc, int col) {
        if(g[sr][sc]==col)
            return g;
        
        int m=g.size(),n=g[0].size();
        dfs(g,m,n,sr,sc,col,g[sr][sc]);
        return g;
    }
    
    /*
    void bfs(vector<vector<int>>& g,int m,int n,int sr,int sc,int nc)
    {
        queue<pair<int,int>> q;
        
        int oc=g[sr][sc];
        g[sr][sc]=nc;
        q.push({sr,sc});
        
        while(!q.empty())
        {
            sr=q.front().first;
            sc=q.front().second;
            q.pop();
            
            if(sr-1>=0 && g[sr-1][sc]==oc)
            {
                g[sr-1][sc]=nc;
                q.push({sr-1,sc});
            }
                
            if(sr+1<m && g[sr+1][sc]==oc)
            {
                g[sr+1][sc]=nc;
                q.push({sr+1,sc});
            }
            
            if(sc-1>=0 && g[sr][sc-1]==oc)
            {
                g[sr][sc-1]=nc;
                q.push({sr,sc-1});
            }
                
            if(sc+1<n && g[sr][sc+1]==oc)
            {
                g[sr][sc+1]=nc;
                q.push({sr,sc+1});
            }
        }
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& g, int sr, int sc, int col) {
        if(g[sr][sc]==col)
            return g;
    
        int m=g.size(),n=g[0].size();
        bfs(g,m,n,sr,sc,col);
        return g;
    }
    */
    
    /*
    void dfs(vector<vector<int>>& g,int m,int n,int sr,int sc,int nc,int oc,vector<vector<bool>> &vis)
    {
        if(sr<0 || sc<0 || sr>=m || sc>=n || g[sr][sc]!=oc || vis[sr][sc])
            return;
        
        g[sr][sc]=nc;
        vis[sr][sc]=1;
        
        dfs(g,m,n,sr-1,sc,nc,oc,vis);
        dfs(g,m,n,sr+1,sc,nc,oc,vis);
        dfs(g,m,n,sr,sc-1,nc,oc,vis);
        dfs(g,m,n,sr,sc+1,nc,oc,vis);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& g, int sr, int sc, int col) {
        int m=g.size(),n=g[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        dfs(g,m,n,sr,sc,col,g[sr][sc],vis);
        return g;
    }
    */
    
    /*
    void bfs(vector<vector<int>>& g,int m,int n,int sr,int sc,int nc)
    {
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        queue<pair<int,int>> q;
        
        int oc=g[sr][sc];
        vis[sr][sc]=1;
        q.push({sr,sc});
        
        while(!q.empty())
        {
            sr=q.front().first;
            sc=q.front().second;
            q.pop();
            
            g[sr][sc]=nc;
            
            if(sr-1>=0 && g[sr-1][sc]==oc && !vis[sr-1][sc])
            {
                vis[sr-1][sc]=1;
                q.push({sr-1,sc});
            }
                
            if(sr+1<m && g[sr+1][sc]==oc && !vis[sr+1][sc])
            {
                vis[sr+1][sc]=1;
                q.push({sr+1,sc});
            }
            
            if(sc-1>=0 && g[sr][sc-1]==oc && !vis[sr][sc-1])
            {
                vis[sr][sc-1]=1;
                q.push({sr,sc-1});
            }
                
            if(sc+1<n && g[sr][sc+1]==oc && !vis[sr][sc+1])
            {
                vis[sr][sc+1]=1;
                q.push({sr,sc+1});
            }
        }
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& g, int sr, int sc, int col) {
        int m=g.size(),n=g[0].size();
        bfs(g,m,n,sr,sc,col);
        return g;
    }
    */
};