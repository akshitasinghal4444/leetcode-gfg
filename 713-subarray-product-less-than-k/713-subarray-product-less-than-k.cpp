class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        int i,n=a.size();
        long p=1;
        int st=0,ans=0;
        
        for(i=0;i<n;i++)
        {
            p*=a[i];
            
            if(p>=k)
            {
                while(st<=i && p>=k)
                    p/=a[st++];
            }
                
            ans+=(i-st+1);
        }
        return ans;
    }
};