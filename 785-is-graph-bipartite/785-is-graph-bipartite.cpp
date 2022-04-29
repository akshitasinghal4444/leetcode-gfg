class Solution {
public:
    
    bool bfs(vector<vector<int>>& g,int in,int n,vector<int> &color)
    {
        color[in]=1;
        queue<int> q;
        q.push(in);
        
        while(!q.empty())
        {
            in=q.front();
            q.pop();
            
            for(int i:g[in])
            {
                if(color[i]==color[in])
                    return 0;
                
                if(color[i]==0)
                {
                    color[i]=-color[in];
                    q.push(i);
                }
            }
        }
        
        return 1;
    }
    
    bool isBipartite(vector<vector<int>>& g)
    {
        int i,n=g.size();
        vector<int> color(n,0);
        
        for(i=0;i<n;i++)
        {
            if(color[i]==0 && !bfs(g,i,n,color))
                return 0;
        }
        
        return 1;
    }
    
    /*
    bool dfs(vector<vector<int>>& g,vector<int> &color,int in,int col)
    {
        int nc=(col==0)?1:0;
        color[in]=col;
        
        int i,n=g[in].size();
        
        for(i=0;i<n;i++)
        {
            if(color[g[in][i]]==col)
              return 0;
                
            if(color[g[in][i]]==-1 && !dfs(g,color,g[in][i],nc))
                return 0;
        }
        
        return 1;
    }
    
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size();
        int i;
        vector<int> color(n,-1);
        
        for(i=0;i<n;i++)
        {
            if(color[i]==-1 && !dfs(g,color,i,0))
                return 0;
        }
        
        return 1;
    }
    */
    
    /*
    bool bfs(vector<vector<int>>& g,vector<int> &color,int in)
    {
        queue<int> q;
        q.push(in);
        color[in]=0;
        
        while(!q.empty())
        {
            in=q.front();
            q.pop();
            
            int i,n=g[in].size();
            int nc=(color[in]==0)?1:0;
            
            for(i=0;i<n;i++)
            {
                if(color[g[in][i]]==color[in])
                  return 0;
                
                if(color[g[in][i]]==-1)
                {
                    color[g[in][i]]=nc;
                    q.push(g[in][i]);
                }
            }
        }
        return 1;
    }
    
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size();
        int i;
        vector<int> color(n,-1);
        
        for(i=0;i<n;i++)
        {
            if(color[i]==-1 && !bfs(g,color,i))
                return 0;
        }
        
        return 1;
    }
    */
};