class Solution {
public:
    int maxProfit(vector<int>& a)
    {
        int n=a.size();
        int i,b=-a[0],s=0,c=0;
        
        for(i=1;i<n;i++)
        {
            int nb,ns,nc;
            
            nb=c-a[i];
            ns=b+a[i];
            nc=s;
            
            b=max(b,nb);
            s=max(s,ns);
            c=max(c,nc);
        }
        return s;
    }
    
    /*
    int maxProfit(vector<int>& a) {
        int n=a.size();
        int b=-a[0],s=0,c=0;
        int nb,ns,nc;
        int i;
        
        for(i=1;i<n;i++)
        {
            nb=c-a[i];
            ns=b+a[i];
            nc=s;
            
            b=max(nb,b);
            s=max(ns,s);
            c=max(nc,c);
        }
        return s;
    }
    */
};