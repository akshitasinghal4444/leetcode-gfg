class Solution {
public:
    int maxProfit(vector<int>& a)
    {
        int n=a.size(),i;
        int b=-a[0],s=0,c=0;
        
        for(i=1;i<n;i++)
        {
            int nb,ns,nc;
            nb=c-a[i];
            ns=b+a[i];
            nc=s;
            
            b=max(b,nb);
            s=max(s,ns);
            c=nc;
        }
        
        return s;
    }
};