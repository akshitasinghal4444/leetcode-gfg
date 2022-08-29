class Solution {
public:
    bool comp(string h,string n,int in,int nn)
    {
        int i;
        for(i=0;i<nn;i++)
        {
            if(n[i]!=h[i+in])
                return 0;
        }
        
        return 1;
    }
    
    int strStr(string h, string n) {
        int i,nh=h.length(),nn=n.length();
        int hh=0,hn=0;
        int base=26,prime=101,mul=1;
        
        if(nn==0)
            return 0;
        
        if(nh<nn)
            return -1;
        
        for(i=0;i<nn-1;i++)
            mul=(mul*base)%prime;
        
        for(i=0;i<nn;i++)
        {
            hh=((hh*base)%prime+h[i])%prime;
            hn=((hn*base)%prime+n[i])%prime;            
        }

        if(hh==hn && comp(h,n,0,nn))
            return 0;
        
        for(i;i<nh;i++)
        {
            hh=(hh-(h[i-nn]*mul)%prime)%prime;
            hh=((hh*base)%prime+h[i])%prime;
            
            if(hh==hn && comp(h,n,i-nn+1,nn))
                return i-nn+1;
        }
        
        return -1;
        
    }
};