class Solution {
public:
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
};