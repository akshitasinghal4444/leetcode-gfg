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
};