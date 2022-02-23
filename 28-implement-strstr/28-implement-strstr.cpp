class Solution {
public:
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
                
        cout<<0<<" "<<hh<<" "<<hn<<endl;
        if(hh==hn && comp(h,n,0,nn))
            return 0;
        
        for(i;i<nh;i++)
        {
            // hh=((hh*p)%m+(h[i]))%m;
            // hh=(hh-(d*(h[i-nn]))%m)%m;
            
            hh=(hh-(d*(h[i-nn]))%m)%m;
            hh=(hh*p)%m;
            hh=(hh+(h[i]))%m;

            cout<<i-nn+1<<" "<<hh<<" "<<hn<<endl;
            if(hh==hn && comp(h,n,i-nn+1,nn))
            return i-nn+1;
        }
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
        
        for(i=0;i<nn;i++)
            d=(d*p)%m;
        
        for(i=0;i<nn;i++)
        {
            hh=((hh*p)%m+(h[i]-'a'+1))%m;
            hn=((hn*p)%m+(n[i]-'a'+1))%m;
        }
                
        cout<<0<<" "<<hh<<" "<<hn<<endl;
        if(hh==hn && comp(h,n,0,nn))
            return 0;
        
        for(i;i<nh;i++)
        {
            hh=((hh*p)%m+(h[i]-'a'+1))%m;
            hh=(hh-(d*(h[i-nn]-'a'+1))%m)%m;
            
            // hh=(hh-(d*(h[i-nn]-'a'+1))%m)%m;
            // hh=(hh*p)%m;
            // hh=(hh+(h[i]-'a'+1))%m;

            cout<<i-nn+1<<" "<<hh<<" "<<hn<<endl;
            if(hh==hn && comp(h,n,i-nn+1,nn))
            return i-nn+1;
        }
        return -1;
    }
    */
};