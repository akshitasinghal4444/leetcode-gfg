class Solution {
public:
    
    bool dfs(vector<vector<char>>& b,int m,int n,int i,int j,string &s,int in)
    {
        if(in==s.length())
            return 1;
        
        if(i<0 || j<0 || i>=m || j>=n || s[in]!=b[i][j])
            return 0;
        
        char c=b[i][j];
        b[i][j]='.';
        
        bool x=0;
        
        if(dfs(b,m,n,i-1,j,s,in+1) || dfs(b,m,n,i+1,j,s,in+1) || dfs(b,m,n,i,j-1,s,in+1) || dfs(b,m,n,i,j+1,s,in+1))
            x=1;
        
        b[i][j]=c;
        return x;
    }
    
    bool exist(vector<vector<char>>& b, string s) {
        int m=b.size(),n=b[0].size();
        int i,j;
        vector<int> f(256,0);
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                f[b[i][j]]++;
            }
        }
        
        for(char c:s)
        {
            if(--f[c]<0)
                return 0;
        }
            
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(b[i][j]==s[0] && dfs(b,m,n,i,j,s,0))
                    return 1;
            }
        }
        
        return 0;
    }
};