class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        int i,mn=INT_MAX,mx=INT_MIN,ans=0,maxr=0;
        vector<int> maxl(n,0);
        
        for(i=0;i<n;i++)
        {
            mn=min(mn,a[i]);
            
            if(i==0)
                maxl[i]=a[i]-mn;
            else
                maxl[i]=max(maxl[i-1],a[i]-mn);
        }
        
        for(i=n-1;i>=0;i--)
        {
            mx=max(mx,a[i]);
            maxr=max(maxr,mx-a[i]);
            maxl[i]+=maxr;
        }
        
        for(i=0;i<n;i++)
        {
            ans=max(ans,maxl[i]);
        }
        
        return ans;
    }
    
    /*
    int maxProfit(vector<int>& a) {
        int n=a.size();
        int i,mn=INT_MAX,mx=INT_MIN,ans=0;
        vector<int> maxl(n,0),maxr(n,0);
        
        for(i=0;i<n;i++)
        {
            mn=min(mn,a[i]);
            
            if(i==0)
                maxl[i]=a[i]-mn;
            else
                maxl[i]=max(maxl[i-1],a[i]-mn);
        }
        
        for(i=n-1;i>=0;i--)
        {
            mx=max(mx,a[i]);
            
            if(i==n-1)
                maxr[i]=mx-a[i];
            else
                maxr[i]=max(maxr[i+1],mx-a[i]);
        }
        
        for(i=0;i<n;i++)
        {
            ans=max(ans,maxl[i]+maxr[i]);
        }
        
        return ans;
    }
    */
};