class Solution {
public:
    
    void dfs(vector<int> *g,int n,vector<bool> &vis,int in,int &c)
    {
        if(vis[in])
            return;
        
        vis[in]=1;
        c++;
        
        for(int x:g[in])
            dfs(g,n,vis,x,c);
        
    }
    
    int removeStones(vector<vector<int>>& a) {
        int i,j,n=a.size();
        int ans=0;
        vector<int> g[n];
        vector<bool> vis(n,0);
        
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {   
                if(a[i][0]==a[j][0] || a[i][1]==a[j][1])
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }                   
            }
        }
        
        for(i=0;i<n;i++)
        {
            if(!vis[i])
            {
                int c=0;
                dfs(g,n,vis,i,c);
                ans+=c-1;
            }
        }
        
        return ans;
        
    }
};