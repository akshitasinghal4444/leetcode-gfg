class Solution {
public:
    int rob(vector<int>& a) {
        
        if(a.size()==1)
            return a[0];
        
        int i,j,n=a.size();
        int inc1=a[0],exc1=0;
        int inc2=a[1],exc2=0;
        
        for(i=1,j=2;j<n;i++,j++)
        {
            int ninc1,nexc1,ninc2,nexc2;
            
            ninc1=exc1+a[i];
            nexc1=max(inc1,exc1);
            
            ninc2=exc2+a[j];
            nexc2=max(inc2,exc2);
            
            inc1=ninc1,exc1=nexc1;
            inc2=ninc2,exc2=nexc2;
        }
        
        return max({inc1,exc1,inc2,exc2});
    }
};