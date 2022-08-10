class Solution {
public:
    int pivotIndex(vector<int>& a) {
        int i,n=a.size();
        int sum[n];
        
        sum[0]=a[0];
        for(i=1;i<n;i++)
            sum[i]=sum[i-1]+a[i];
        
        if(sum[n-1]-sum[0]==0)
            return 0;
            
        for(i=1;i<n-1;i++)
        {
            if(sum[i-1]==sum[n-1]-sum[i])
                return i;
        }
        
        if(sum[n-2]==0)
            return n-1;
        
        return -1;
    }
};