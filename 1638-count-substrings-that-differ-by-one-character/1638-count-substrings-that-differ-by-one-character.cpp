class Solution {
public:
    int countSubstrings(string s, string t) {
        int ns,nt,i,j,c=0;
        ns=s.length();
        nt=t.length();
        
        for(i=0;i<ns;i++)
        {
            for(j=0;j<nt;j++)
            {
                int d=0;
                int x,y;
                x=i;
                y=j;
                while(x<ns && y<nt)
                {
                    if(s[x]!=t[y])
                        d++;
                    if(d==1)
                       c++;
                    if(d==2)
                        break;
                    
                    x++;
                    y++;
                }
            }
        }
        
        return c;
    }
    
    
    /*
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
    */
};