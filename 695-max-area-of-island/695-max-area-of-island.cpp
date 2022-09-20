class Solution {
public:
    
    int t;
    
    void bfs(vector<vector<int>>& g,int m,int n,int i,int j)
    {
        queue<pair<int,int>> q;
        q.push({i,j});
        g[i][j]=0;
        
        while(!q.empty())
        {
            i=q.front().first;
            j=q.front().second;
            q.pop();
            t++;
            
            if(i-1>=0 && g[i-1][j])
            {
                q.push({i-1,j});
                g[i-1][j]=0;
            }
            
            if(i+1<m && g[i+1][j])
            {
                q.push({i+1,j});
                g[i+1][j]=0;
            }
            
            if(j-1>=0 && g[i][j-1])
            {
                q.push({i,j-1});
                g[i][j-1]=0;
            }
            
            if(j+1<n && g[i][j+1])
            {
                q.push({i,j+1});
                g[i][j+1]=0;
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size();
        int i,j;
        int ans=0;
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(g[i][j])
                {
                    t=0;
                    bfs(g,m,n,i,j);
                    ans=max(ans,t);
                }                  
            }
        }
        
        return ans;
    }
    
    /*
    int t;
    
    void dfs(vector<vector<int>>& g,int m,int n,int i,int j)
    {
        if(i<0 || j<0 || i>=m || j>=n || !g[i][j])
            return;
        
        t++;
        g[i][j]=0;
        
        dfs(g,m,n,i-1,j);
        dfs(g,m,n,i+1,j);
        dfs(g,m,n,i,j-1);
        dfs(g,m,n,i,j+1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& g) {
        int m=g.size(),n=g[0].size();
        int i,j;
        int ans=0;
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(g[i][j])
                {
                    t=0;
                    dfs(g,m,n,i,j);
                    ans=max(ans,t);
                }                  
            }
        }
        
        return ans;
    }
    */
};