class Solution {
public:
    int maxProfit(vector<int>& a)
    {
        int n=a.size(),i;
        int ans=0,b=n-1;
        
        for(i=n-2;i>=0;i--)
        {
            if(a[i]<=a[i+1])
                continue;
            else
            {
                ans+=a[b]-a[i+1];
                b=i;
            }
        }
        if(i==-1)
            ans+=a[b]-a[i+1];
        return ans;
    }
    
    /*
    int maxProfit(vector<int>& a) {
        int n=a.size();
        int i,j,mp=0;
        for(i=0;i<n;i++)
        {
            j=i+1;
            while(j<n && a[j]>a[j-1])
                j++;
            mp+=a[j-1]-a[i];
            i=j-1;
        }
        return mp;
    }
    */
};