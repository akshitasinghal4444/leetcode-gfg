class Solution {
public:
    int minCut(string s)
    {
        int n=s.length();
        int i,j,k;
        
        vector<vector<bool>> palindrome(n,vector<bool>(n));
        
        for(k=0;k<n;k++)
        {
            for(i=0,j=k;j<n;i++,j++)
            {
                if(k==0)
                    palindrome[i][j]=1;
                else if(k==1)
                    palindrome[i][j]=(s[i]==s[j]);
                else 
                    palindrome[i][j]=((s[i]==s[j]) && palindrome[i+1][j-1]);
            }
        }
        
        vector<int> cuts(n);
        cuts[0]=0;
        
        for(i=1;i<n;i++)
        {
            int mn=INT_MAX;
            for(j=i;j>=0;j--)
            {
                if(palindrome[j][i])
                {
                    if(j==0)
                        mn=-1;
                    else
                        mn=min(mn,cuts[j-1]);
                }
            }
            cuts[i]=mn+1;
        }
        
        return cuts[n-1];
    }
    
    /*
    int minCut(string s) {
        int n=s.length();
        int i,j,k;
        
        vector<vector<bool>> palindrome(n,vector<bool>(n));
        
        for(k=0;k<n;k++)
        {
            for(i=0,j=k;j<n;i++,j++)
            {
                if(k==0)
                    palindrome[i][j]=1;
                else if(k==1)
                    palindrome[i][j]=(s[i]==s[j]);
                else 
                    palindrome[i][j]=((s[i]==s[j]) && palindrome[i+1][j-1]);
            }
        }
        
        vector<vector<int>> cuts(n,vector<int>(n,0));
        
        for(k=0;k<n;k++)
        {
            for(i=0,j=k;j<n;j++,i++)
            {
                if(k==0 || palindrome[i][j])
                    cuts[i][j]=0;
                else if(k==1)
                {
                    if(s[i]==s[j])
                        cuts[i][j]=0;
                    else
                        cuts[i][j]=1;
                }
                else
                {
                    int mn=INT_MAX;
                    for(int t=i;t<j;t++)
                        mn=min(mn,cuts[i][t]+cuts[t+1][j]);
                    
                    cuts[i][j]=mn+1;
                }
            }
        }
        
        return cuts[0][n-1];
    }
*/
};