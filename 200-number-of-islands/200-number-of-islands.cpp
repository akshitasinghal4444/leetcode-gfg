class Solution {
public:
    void bfs(vector<vector<char>>& g,int m,int n,int i,int j)
    {
        queue<pair<int,int>> q;
        g[i][j]='0';
        
        if(i-1>=0 && g[i-1][j]=='1')
        {
            q.push({i-1,j});
            g[i-1][j]='0';
        }
        
        if(j+1<n && g[i][j+1]=='1')
        {
            q.push({i,j+1});
            g[i][j+1]='0';
        }
        
        if(i+1<m && g[i+1][j]=='1')
        {
            q.push({i+1,j});
            g[i+1][j]='0';
        }
        
        if(j-1>=0 && g[i][j-1]=='1')
        {
            q.push({i,j-1});
            g[i][j-1]='0';
        }
        
        while(!q.empty())
        {
            i=q.front().first;
            j=q.front().second;
            
            q.pop();
            bfs(g,m,n,i,j);
        }
    }
    
    int numIslands(vector<vector<char>>& g)
    {
        int m,n;
        m=g.size();
        n=g[0].size();
        int i,j,c=0;
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(g[i][j]=='1')
                {
                    bfs(g,m,n,i,j);
                    c++;
                }
            }
        }
        return c;
    }
    
    /*
    void dfs(vector<vector<char>>& g,int m,int n,int i,int j)
    {
        g[i][j]='0';
        
        if(i-1>=0 && g[i-1][j]=='1')
            dfs(g,m,n,i-1,j);
        
        if(j+1<n && g[i][j+1]=='1')
            dfs(g,m,n,i,j+1);
        
        if(i+1<m && g[i+1][j]=='1')
            dfs(g,m,n,i+1,j);
        
        if(j-1>=0 && g[i][j-1]=='1')
            dfs(g,m,n,i,j-1);
        
    }
    
    int numIslands(vector<vector<char>>& g)
    {
        int m,n;
        m=g.size();
        n=g[0].size();
        int i,j,c=0;
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(g[i][j]=='1')
                {
                    dfs(g,m,n,i,j);
                    c++;
                }
            }
        }
        return c;
    }
    */
};