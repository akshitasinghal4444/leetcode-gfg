class Solution {
public:
    
    bool bfs(vector<vector<int>>& g,int n,int in,int c,vector<int> &col)
    {
        queue<int> q;
        q.push(in);
        col[in]=c;
        
        while(!q.empty())
        {
            in=q.front();
            q.pop();
            
            for(int x:g[in])
            {
                if(col[x])
                {
                    if(col[x]==col[in])
                        return 0;
                }
                else
                {
                    col[x]=-col[in];
                    q.push(x);
                }
            }
        }
        
        return 1;
    }
    
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size();
        vector<int> col(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(!col[i] && !bfs(g,n,i,1,col))
                return 0;
        }
        
        return 1;
    }
    
    /*
    bool dfs(vector<vector<int>>& g,int n,int in,int c,vector<int> &col)
    {
        if(col[in]!=0)
        {
            if(col[in]!=c)
                return 0;
            
            return 1;
        }
                
        col[in]=c;
                
        for(int x:g[in])
        {
            if(!dfs(g,n,x,-c,col))
                return 0;         
        }
        
        return 1;
    }
    
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size();
        vector<int> col(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(!col[i] && !dfs(g,n,i,1,col))
                return 0;
        }
        
        return 1;
    }
    */
};