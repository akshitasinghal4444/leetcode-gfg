class Solution {
public:
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
    
    /*
    bool isValid(vector<vector<char>>& g,int i,int j,int m,int n)
    {
        return (i>=0 && j>=0 && i<m && j<n && g[i][j]=='1');
    }
    void dfs(vector<vector<char>>& g,int i,int j,int m,int n)
    {
        g[i][j]='0';
        int dx[]={-1,0,0,1},dy[]={0,-1,1,0};
        int k;
        for(k=0;k<4;k++)
        {
            if(isValid(g,i+dx[k],j+dy[k],m,n))
                dfs(g,i+dx[k],j+dy[k],m,n);
        }
    }
    int numIslands(vector<vector<char>>& g) {
        int m,n;
        m=g.size();
        n=g[0].size();
        int ans=0;
        int i,j;
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                if(g[i][j]!='0')
                {
                    ans++;
                    dfs(g,i,j,m,n);
                }
        return ans;
    }
    */
};