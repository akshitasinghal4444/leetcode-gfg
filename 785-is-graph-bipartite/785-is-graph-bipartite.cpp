class Solution {
public:
    
    bool color(vector<vector<int>>& g,int n,int in,int c,vector<int> &col)
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
            if(!color(g,n,x,-c,col))
                return 0;         
        }
        
        return 1;
    }
    
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size();
        vector<int> col(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(!col[i] && !color(g,n,i,1,col))
                return 0;
        }
        
        return 1;
    }
};