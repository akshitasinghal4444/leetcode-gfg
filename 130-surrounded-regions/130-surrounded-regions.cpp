class Solution {
public:
    void dfs(vector<vector<char>>& a,int i,int j,int m,int n,vector<vector<bool>> &vis,char c)
    {
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j] || a[i][j]=='X')
            return;
        
        a[i][j]=c;
        vis[i][j]=1;
        
        dfs(a,i-1,j,m,n,vis,c);
        dfs(a,i+1,j,m,n,vis,c);
        dfs(a,i,j-1,m,n,vis,c);
        dfs(a,i,j+1,m,n,vis,c);
    }
    
    void solve(vector<vector<char>>& a) {
        int m=a.size(),n=a[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        int i,j;
        
        for(i=0;i<m;i++)
        {
            if(a[i][0]=='O')
                dfs(a,i,0,m,n,vis,'O');
            
            if(a[i][n-1]=='O')
                dfs(a,i,n-1,m,n,vis,'O');                
        }
        
        for(j=0;j<n;j++)
        {
            if(a[0][j]=='O')
                dfs(a,0,j,m,n,vis,'O');
             
            if(a[m-1][j]=='O')
                dfs(a,m-1,j,m,n,vis,'O');
        }
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]=='O')
                    dfs(a,i,j,m,n,vis,'X');
            }
        }
    }
    
    /*
    void bfs(vector<vector<char>>& a,int i,int j,int m,int n,vector<vector<bool>> &vis,char c)
    {
        queue<pair<int,int>> q;
        q.push({i,j});
        a[i][j]=c;
        vis[i][j]=1;
        
        while(!q.empty())
        {
            i=q.front().first;
            j=q.front().second;
            q.pop();
            
            if(i-1>=0 && a[i-1][j]=='O' && !vis[i-1][j])
            {
                vis[i-1][j]=1;
                a[i-1][j]=c;
                q.push({i-1,j});
            }
            
            if(i+1<m && a[i+1][j]=='O' && !vis[i+1][j])
            {
                vis[i+1][j]=1;
                a[i+1][j]=c;
                q.push({i+1,j});
            }
            
            if(j-1>=0 && a[i][j-1]=='O' && !vis[i][j-1])
            {
                vis[i][j-1]=1;
                a[i][j-1]=c;
                q.push({i,j-1});
            }
            
            if(j+1<n && a[i][j+1]=='O' && !vis[i][j+1])
            {
                vis[i][j+1]=1;
                a[i][j+1]=c;
                q.push({i,j+1});
            }
        }
        
    }
    
    void solve(vector<vector<char>>& a) {
        int m=a.size(),n=a[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        int i,j;
        
        for(i=0;i<m;i++)
        {
            if(a[i][0]=='O' && !vis[i][0])
                bfs(a,i,0,m,n,vis,'O');
            
            if(a[i][n-1]=='O' && !vis[i][n-1])
                bfs(a,i,n-1,m,n,vis,'O');                
        }
        
        for(j=0;j<n;j++)
        {
            if(a[0][j]=='O' && !vis[0][j])
                bfs(a,0,j,m,n,vis,'O');
             
            if(a[m-1][j]=='O' && !vis[m-1][j])
                bfs(a,m-1,j,m,n,vis,'O');
        }
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]=='O' && !vis[i][j])
                    bfs(a,i,j,m,n,vis,'X');
            }
        }
    }
    */
};