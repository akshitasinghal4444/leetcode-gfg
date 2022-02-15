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
    
    /*
    bool isValid(vector<vector<int>>& g,int i,int j,int m,int n)
    {
        return (i>=0 && j>=0 && i<m && j<n && g[i][j]);
    }
    
    int dfs(vector<vector<int>>& g,int i,int j,int m,int n)
    {
        int x=g[i][j];
        int ans=0;
        g[i][j]=0;
        int dx[]={-1,0,0,1};
        int dy[]={0,-1,1,0};
        int k;
        for(k=0;k<4;k++)
        {
            if(isValid(g,i+dx[k],j+dy[k],m,n))
                ans=max(ans,dfs(g,i+dx[k],j+dy[k],m,n));
        }
        g[i][j]=x;
        return ans+x;
    }
    
    int getMaximumGold(vector<vector<int>>& g) {
        int i,j;
        int mg1=0,mg2=0;
        int m,n;
        m=g.size();
        n=g[i].size();
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                mg2=0;
                if(g[i][j])
                    mg2=dfs(g,i,j,m,n);
                mg1=max(mg1,mg2);
            }
        }
        return mg1;
    }
    */
};