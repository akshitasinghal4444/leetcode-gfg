class Solution {
public:
    
    bool dfs(vector<vector<char>>& a, string s,int m,int n,int i,int j,int l,int in)
    {
        if(in==l)
            return 1;
        
        if(i<0 || j<0 || i>=m || j>=n || a[i][j]!=s[in])
            return 0;
        
        char c=a[i][j];
        a[i][j]='.';
        
        bool x=dfs(a,s,m,n,i-1,j,l,in+1) || dfs(a,s,m,n,i+1,j,l,in+1) || dfs(a,s,m,n,i,j-1,l,in+1) || dfs(a,s,m,n,i,j+1,l,in+1);
        
        a[i][j]=c;
        return x;
    }
    
    bool exist(vector<vector<char>>& a, string s) {
        int m=a.size(),n=a[0].size();
        int i,j,l=s.length();
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]==s[0] && dfs(a,s,m,n,i,j,l,0))
                    return 1;
            }
        }
        
        return 0;
    }
};