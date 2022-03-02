class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m,n;
        m=t.length();
        n=s.length();
        if(n>m)
            return 0;
        if(n==0)
            return 1;
        
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
                j++;
        }
        if(i==n)
            return 1;
        return 0;
    }
    
    /*
    bool match(string s, string t,int ns,int nt,int i,int j)
    {
        if(i==ns)
            return 1;
        
        if(j==nt)
            return 0;
        
        if(s[i]==t[j])
            return match(s,t,ns,nt,i+1,j+1);
        
        return match(s,t,ns,nt,i,j+1);
    }
    
    bool isSubsequence(string s, string t)
    {
        int i,j,ns=s.length(),nt=t.length();
        
        if(ns>nt)
            return 0;
        
        return match(s,t,ns,nt,0,0);
    }
    */
    
    /*
    bool isSubsequence(string s, string t) {
        int f[26]={0};
        int i,j,ns=s.length(),nt=t.length();
        
        if(ns>nt)
            return 0;
        
        for(i=0,j=0;i<ns;i++)
        {
            while(j<nt && s[i]!=t[j])
                j++;
            
            if(j==nt)
                return 0;
            j++;
        }
        
        if(i==ns)
        return 1;
        
        return 0;
    }
    */
};