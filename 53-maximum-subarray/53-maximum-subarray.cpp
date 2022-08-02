class Solution {
public:
    
    int maxSubArray(vector<int>& a) {
        int i,n=a.size();
        int sum=INT_MIN,t=0;
        
        for(i=0;i<n;i++)
        {
            t+=a[i];
            sum=max(sum,t);
            
            if(t<0)
                t=0;
        }
        
        return sum;
    }
    
    
    /*
    int maxSubArray(vector<int>& a)
    {
        int n=a.size();
        int i,s=a[0],ms=a[0];
        for(i=1;i<n;i++)
        {
            if(s<0)
                s=0;
            s+=a[i];
            ms=max(ms,s);
        }
        return ms;
    }
    */
    
    /*
    int maxSubArray(vector<int>& a) {
        int s=a[0],ms=a[0];
        int i,n=a.size();
        for(i=1;i<n;i++)
        {
            s=max(a[i],s+a[i]);
            ms=max(s,ms);
        }
        return ms;
    }
    */
};