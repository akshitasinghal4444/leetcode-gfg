class Solution {
public:
    
    bool dfs(vector<vector<int>>& g,int in,int n,vector<int> &color,int c)
    {
        color[in]=c;

        for(int i:g[in])
        {
            if((color[i]==color[in]) || (color[i]==0 && !dfs(g,i,n,color,-c)))
                return 0;      
        }
        
        return 1;
    }
    
    bool isBipartite(vector<vector<int>>& g)
    {
        int i,n=g.size();
        vector<int> color(n,0);
        
        for(i=0;i<n;i++)
        {
            if(color[i]==0 && !dfs(g,i,n,color,1))
                return 0;
        }
        
        return 1;
    }
    
    /*
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
    */
};