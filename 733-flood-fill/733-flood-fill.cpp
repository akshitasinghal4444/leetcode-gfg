class Solution {
public:
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
};