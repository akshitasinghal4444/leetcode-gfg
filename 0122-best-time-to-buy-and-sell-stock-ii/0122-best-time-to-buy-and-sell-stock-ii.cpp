class Solution {
public:
    int maxProfit(vector<int>& a) {
        int st=0,i,n=a.size();
        int ans=0;
        
        for(i=1;i<n;i++)
        {
            if(a[i]>=a[i-1])
                continue;
            
            ans+=a[i-1]-a[st];
            st=i;
        }
        
        ans+=a[i-1]-a[st];
        
        return ans;
    }
};