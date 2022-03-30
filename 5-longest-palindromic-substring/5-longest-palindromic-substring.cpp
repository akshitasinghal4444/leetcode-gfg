class Solution {
public:
    
    void expand(string &s,int l,int r,int len,int n,int &b,int &e,int &mx)
    {
        while(l>=0 && r<n && s[l]==s[r])
        {
            l--;
            r++;
            len+=2;
        }
        
        if(len>mx)
        {
            mx=len;
            b=l+1;
            e=r-1;
        }
    }
    
    string longestPalindrome(string s)
    {
        int n=s.length();
        int i;
        int mx=1,b=0,e=0;
        
        for(i=0;i<n-1;i++)
        {
            expand(s,i,i+1,0,n,b,e,mx);
            expand(s,i-1,i+1,1,n,b,e,mx);
        }
        
        string ans="";
        for(i=b;i<=e;i++)
            ans+=s[i];
        
        return ans;
    }
    
    /*
    string longestPalindrome(string s)
    {
        int n=s.length();
        bool palindrome[n][n];
        int i,j,k;
        int mx=0,b=-1,e=-1;
        
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
                
                if(palindrome[i][j] && k+1>mx)
                {
                    mx=k;
                    b=i;
                    e=j;
                }
            }
        }
        
        string ans="";
        for(i=b;i<=e;i++)
            ans+=s[i];
        
        return ans;
    }
    */
    
    /*
    string longestPalindrome(string s)
    {
        int n=s.length();
        int i;
        int mx=1,b=0,e=0;
        
        for(i=0;i<n-1;i++)
        {
            int l=i;
            int r=i+1;
            int len=0;
            while(l>=0 && r<n && s[l]==s[r])
            {
                l--;
                r++;
                len+=2;
            }
            if(len>mx)
            {
                mx=len;
                b=l+1;
                e=r-1;
            }
            
            l=i-1;
            r=i+1;
            len=1;
            while(l>=0 && r<n && s[l]==s[r])
            {
                l--;
                r++;
                len+=2;
            }
            if(len>mx)
            {
                mx=len;
                b=l+1;
                e=r-1;
            }            
        }
        
        string ans="";
        for(i=b;i<=e;i++)
            ans+=s[i];
        
        return ans;
    }
    */
};