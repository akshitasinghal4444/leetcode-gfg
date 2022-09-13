class Solution {
public:
    vector<int> count(string s)
    {
        int z=0,o=0;
        for(char c:s)
        {
            if(c=='0')
                z++;
            else
                o++;
        }
        
        return {z,o};
    }
    
    int findMaxForm(vector<string>& a, int m, int n)
    {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int i,j;
        
        for(string s:a)
        {
            auto f=count(s);
            
            for(i=m;i>=0;i--)
            {
                if(i-f[0]<0)
                    continue;
                
                for(j=n;j>=0;j--)
                {
                    if(j-f[1]>=0)
                    dp[i][j]=max(dp[i][j],dp[i-f[0]][j-f[1]]+1);
                }
            }
        }
        
        return dp[m][n];
    }
    
    /*
    int find(vector<string>& a, int m, int n,int in,int l,int f[][2],vector<vector<vector<int>>> &dp,int z,int o)
    {        
        if(in==l)
            return 0;
              
        if(dp[in][z][o]==-1)
        {
            dp[in][z][o]=find(a,m,n,in+1,l,f,dp,z,o);
            
            if(z+f[in][0]<=m && o+f[in][1]<=n)
            dp[in][z][o]=max(dp[in][z][o],find(a,m,n,in+1,l,f,dp,z+f[in][0],o+f[in][1])+1);
        }
        
        return dp[in][z][o];
    }
    
    int findMaxForm(vector<string>& a, int m, int n) {
        int l=a.size();
        int f[l][2];
        vector<vector<vector<int>>> dp(l+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        int i;
        
        for(i=0;i<l;i++)
        {
            f[i][0]=f[i][1]=0;
            for(char c:a[i])
            {
                if(c=='0')
                    f[i][0]++;
                else
                    f[i][1]++;
            }
        }
        
        return find(a,m,n,0,l,f,dp,0,0);
    }
    */
};