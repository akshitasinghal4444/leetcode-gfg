class Solution {
public:
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
};