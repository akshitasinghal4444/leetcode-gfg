class Solution {
public:
    int countSubstrings(string s, string t) {
        int ns,nt,i,j,k,l;
        ns=s.length();
        nt=t.length();
        
        int dp[ns][nt];
        for(i=0;i<ns;i++)
        {
            for(j=0;j<nt;j++)
            {
                if(s[i]!=t[j])
                    dp[i][j]=1;
                else
                    dp[i][j]=0;
            }
        }
        
        int c=0;
        for(k=1;k<=ns;k++)
        {
            for(i=0;i<=ns-k;i++)
            {
                for(j=0;j<=nt-k;j++)
                {
                    int x=0;
                    for(l=0;l<k;l++)
                    {
                        if(dp[i+l][j+l]==1)
                            x++;
                    }
                    if(x==1)
                        c++;
                }
            }
            // cout<<c<<endl;
        }
        
        return c;
    }
};