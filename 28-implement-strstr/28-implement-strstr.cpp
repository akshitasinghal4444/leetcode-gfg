class Solution {
public:
    void createlps(string &n,int nn,int *lps)
    {
        int i,j;
        i=-1;
        j=1;
        lps[0]=-1;
        
        while(j<nn)
        {
            if(n[j]==n[i+1])
            {
                lps[j]=i+1;
                i++;
                j++;
            }
            else if(i==-1)
            {
                lps[j]=-1;
                j++;
            }
            else
            {
                i=lps[i];
            }
        }
    }
    
    int strStr(string h, string n)
    {
        if(n=="")
            return 0;
        
        int nh=h.length(),nn=n.length();
        if(nn>nh)
            return -1;
        
        int lps[nn];
        createlps(n,nn,lps);
        
        int i,j=-1;
        
        for(i=0;i<nh;i++)
        {
            if(h[i]==n[j+1])
            {
                j++;
            }
            else if(j!=-1)
            {
                j=lps[j];
                i--;
            }
            
            if(j==nn-1)
                return i-nn+1;
        }
        if(j==nn)
         return i-nn;
        return -1;
    }
    
    /*
    bool comp(string &s1,string &s2,int in,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(s1[in+i]!=s2[i])
                return 0;
        }
        return 1;
    }
    
    int strStr(string h, string n) {
        
        if(n=="")
            return 0;
        
        int nh=h.length(),nn=n.length();
        if(nn>nh)
            return -1;
        
        int p=26,m=101;
        int hh=0,hn=0;
        int i,j,d=1;
        
        for(i=0;i<nn-1;i++)
            d=(d*p)%m;
        
        for(i=0;i<nn;i++)
        {
            hh=((hh*p)%m+(h[i]))%m;
            hn=((hn*p)%m+(n[i]))%m;
        }
                
        if(hh==hn && comp(h,n,0,nn))
            return 0;
        
        for(i;i<nh;i++)
        {   
            hh=(hh-(d*(h[i-nn]))%m)%m;
            hh=(hh*p)%m;
            hh=(hh+(h[i]))%m;

            if(hh==hn && comp(h,n,i-nn+1,nn))
            return i-nn+1;
        }
        return -1;
    }
    */
};