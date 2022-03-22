class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int nc) {
        if(img[sr][sc]==nc)
            return img;
        
        int m=img.size(),n=img[0].size();
        
        queue<pair<int,int>> q;
        q.push({sr,sc});        
        int col=img[sr][sc];
        img[sr][sc]=nc;
        
        while(!q.empty())
        {
            sr=q.front().first;
            sc=q.front().second;
            q.pop();
            
            if(sr-1>=0 && img[sr-1][sc]==col)
            {
                img[sr-1][sc]=nc;
                q.push({sr-1,sc});
            }
                
        
            if(sc-1>=0 && img[sr][sc-1]==col)
            {
                img[sr][sc-1]=nc;
                q.push({sr,sc-1});
            }    
        
            if(sr+1<m && img[sr+1][sc]==col)
            {
                img[sr+1][sc]=nc;
                q.push({sr+1,sc});
            }    
        
            if(sc+1<n && img[sr][sc+1]==col)
            {
                img[sr][sc+1]=nc;
                q.push({sr,sc+1});
            }    
        
        }
        
        return img;
    }

    /*
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int nc) {
        
        int m=img.size(),n=img[0].size();
        
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        
        int col=img[sr][sc];
        img[sr][sc]=nc;
        
        while(!q.empty())
        {
            sr=q.front().first;
            sc=q.front().second;
            q.pop();
            
            if(sr-1>=0 && img[sr-1][sc]==col && !vis[sr-1][sc])
            {
                img[sr-1][sc]=nc;
                q.push({sr-1,sc});
                vis[sr-1][sc]=1;
            }
                
        
            if(sc-1>=0 && img[sr][sc-1]==col && !vis[sr][sc-1])
            {
                img[sr][sc-1]=nc;
                q.push({sr,sc-1});
                vis[sr][sc-1]=1;
            }    
        
            if(sr+1<m && img[sr+1][sc]==col && !vis[sr+1][sc])
            {
                img[sr+1][sc]=nc;
                q.push({sr+1,sc});
                vis[sr+1][sc]=1;
            }    
        
            if(sc+1<n && img[sr][sc+1]==col && !vis[sr][sc+1])
            {
                img[sr][sc+1]=nc;
                q.push({sr,sc+1});
                vis[sr][sc+1]=1;
            }    
        
        }
        
        return img;
    }
    */
    
    /*
    void dfs(vector<vector<int>>& img,vector<vector<bool>> &vis,int m,int n,int i,int j,int nc)
    {
        vis[i][j]=1;
        
        if(i-1>=0 && !vis[i-1][j] && img[i-1][j]==img[i][j])
            dfs(img,vis,m,n,i-1,j,nc);
        
        if(j-1>=0 && !vis[i][j-1] && img[i][j-1]==img[i][j])
            dfs(img,vis,m,n,i,j-1,nc);
        
        if(i+1<m && !vis[i+1][j] && img[i+1][j]==img[i][j])
            dfs(img,vis,m,n,i+1,j,nc);
        
        if(j+1<n && !vis[i][j+1] && img[i][j+1]==img[i][j])
            dfs(img,vis,m,n,i,j+1,nc);
        
        img[i][j]=nc;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int nc) {
        
        int m=img.size(),n=img[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,0));
        
        dfs(img,vis,m,n,sr,sc,nc);
        
        return img;
    }
    */
};