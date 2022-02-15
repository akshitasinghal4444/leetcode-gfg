class Solution {
public:
    bool isValid(vector<vector<int>>& g,int m,int n,int i,int j)
    {
        return (i<m && j<n && i>=0 && j>=0 && g[i][j]);
    }
    
    int dfs(vector<vector<int>>& g,int m,int n,int i,int j)
    {
        int ans=0;
        int t=g[i][j];
        g[i][j]=0;
        
        int x[]={-1,0,1,0},y[]={0,1,0,-1};
        
        for(int k=0;k<4;k++)
        {
            if(isValid(g,m,n,i+x[k],j+y[k]))
            ans=max(ans,dfs(g,m,n,i+x[k],j+y[k]));
        }
        
        g[i][j]=t;
        return t+ans;
    }
    
    int getMaximumGold(vector<vector<int>>& g)
    {
        int ans=0;
        int m,n,i,j;
        m=g.size();
        n=g[0].size();
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(g[i][j])
                {
                    ans=max(ans,dfs(g,m,n,i,j));
                }
            }
        }
        
        return ans;
    }
};