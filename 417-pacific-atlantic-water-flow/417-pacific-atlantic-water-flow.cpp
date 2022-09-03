class Solution {
public:
    vector<vector<int>> ans;
    
    void bfs(vector<vector<int>>& a,int m,int n,vector<vector<bool>> &v1,int i,int j,vector<vector<bool>> &v2)
    {
        if(v1[i][j])
            return;
        
        queue<pair<int,int>> q;
        q.push({i,j});
        v1[i][j]=1;
        
        while(!q.empty())
        {
            i=q.front().first;
            j=q.front().second;
            q.pop();
            
            if(v1[i][j] && v2[i][j])
                ans.push_back({i,j});
            
            if(i+1<m && !v1[i+1][j] && a[i+1][j]>=a[i][j])
            {
                v1[i+1][j]=1;
                q.push({i+1,j});
            }
            
            if(i-1>=0 && !v1[i-1][j] && a[i-1][j]>=a[i][j])
            {
                v1[i-1][j]=1;
                q.push({i-1,j});
            }
            
            if(j+1<n && !v1[i][j+1] && a[i][j+1]>=a[i][j])
            {
                v1[i][j+1]=1;
                q.push({i,j+1});
            }
            
            if(j-1>=0 && !v1[i][j-1] && a[i][j-1]>=a[i][j])
            {
                v1[i][j-1]=1;
                q.push({i,j-1});
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& a) {
        
        int m=a.size(),n=a[0].size();
        int i,j;
        vector<vector<bool>> atlantic(m,vector<bool>(n,0)),pacific(m,vector<bool>(n,0));
        
        for(i=0;i<m;i++)
        {
            bfs(a,m,n,pacific,i,0,atlantic);
            bfs(a,m,n,atlantic,i,n-1,pacific);
        }
        
        for(j=0;j<n;j++)
        {
            bfs(a,m,n,pacific,0,j,atlantic);
            bfs(a,m,n,atlantic,m-1,j,pacific);
        }
        
        return ans;
    }
    
    /*
    void bfs(vector<vector<int>>& a,int m,int n,set<pair<int,int>> &s)
    {
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        int i,j;
        
        for(auto p:s)
        {
            i=p.first;
            j=p.second;
            q.push({i,j});
            vis[i][j]=1;
        }
        
        while(!q.empty())
        {
            i=q.front().first;
            j=q.front().second;
            q.pop();
            
            if(i+1<m && !vis[i+1][j] && a[i+1][j]>=a[i][j])
            {
                vis[i+1][j]=1;
                q.push({i+1,j});
                s.insert({i+1,j});
            }
            
            if(i-1>=0 && !vis[i-1][j] && a[i-1][j]>=a[i][j])
            {
                vis[i-1][j]=1;
                q.push({i-1,j});
                s.insert({i-1,j});
            }
            
            if(j+1<n && !vis[i][j+1] && a[i][j+1]>=a[i][j])
            {
                vis[i][j+1]=1;
                q.push({i,j+1});
                s.insert({i,j+1});
            }
            
            if(j-1>=0 && !vis[i][j-1] && a[i][j-1]>=a[i][j])
            {
                vis[i][j-1]=1;
                q.push({i,j-1});
                s.insert({i,j-1});
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        set<pair<int,int>> pacific,atlantic;
        vector<vector<int>> ans;
        
        int i,j;
        
        
        for(i=0;i<m;i++)
        {
            pacific.insert({i,0});
            atlantic.insert({i,n-1});
        }
        
        for(j=0;j<n;j++)
        {
            pacific.insert({0,j});
            atlantic.insert({m-1,j});
        }
        
        bfs(a,m,n,pacific);
        bfs(a,m,n,atlantic);
        
        for(auto p:pacific)
        {            
            if(atlantic.find(p)!=atlantic.end())
                ans.push_back({p.first,p.second});
        }
        
        return ans;
    }
    */
};