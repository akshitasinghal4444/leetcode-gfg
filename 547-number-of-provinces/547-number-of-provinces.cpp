class Solution {
public:
    
    void bfs(vector<vector<int>>& a,int n,vector<bool> &vis,int in)
    {
        queue<int> q;
        q.push(in);
        vis[in]=1;
        
        while(!q.empty())
        {
            in=q.front();
            q.pop();
            
            for(int i=0;i<n;i++)
            {
                if(a[in][i] && !vis[i])
                {
                    vis[i]=1;
                    q.push(i);
                }
            }
        }  
    }
    
    int findCircleNum(vector<vector<int>>& a) {
        int i,n=a.size();
        int ans=0;
        vector<bool> vis(n,0);
        
        for(i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans++;
                bfs(a,n,vis,i);
            }
        }
        
        return ans;
    }
    
    /*
    void dfs(vector<vector<int>>& a,int n,vector<bool> &vis,int in)
    {
        vis[in]=1;
        
        for(int i=0;i<n;i++)
        {
            if(a[in][i] && !vis[i])
                dfs(a,n,vis,i);
        }
    }
    
    int findCircleNum(vector<vector<int>>& a) {
        int i,n=a.size();
        int ans=0;
        vector<bool> vis(n,0);
        
        for(i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(a,n,vis,i);
            }
        }
        
        return ans;
    }
    */
};