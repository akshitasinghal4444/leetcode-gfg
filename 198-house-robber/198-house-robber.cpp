class Solution {
public:
    int rob(vector<int>& a)
    {
        int n=a.size(),i;
        int in,ex,ni,ne;
        in=a[0];
        ex=0;
        
        for(i=1;i<n;i++)
        {
            ni=ex+a[i];
            ne=max(ex,in);
            
            in=ni;
            ex=ne;
        }
        return max(in,ex);
    }
    
};