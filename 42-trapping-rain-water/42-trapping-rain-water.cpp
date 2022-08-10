class Solution {
public:
    int trap(vector<int>& a)
    {
        int n=a.size();
        int l=0,r=n-1,maxl=0,maxr=0;
        int ans=0;
        
        while(l<=r)
        {
            maxl=max(a[l],maxl);
            maxr=max(a[r],maxr);
            
            if(maxl<=maxr)
            {
                ans+=maxl-a[l];
                l++;
            }
            else
            {
                ans+=maxr-a[r];
                r--;
            }
        }
        
        return ans;
    }
    
    /*
    int trap(vector<int>& a) {
        int i,j,n=a.size();
        int ans=0;
        vector<int> w(n,INT_MAX);
        
        int mxl=0,mxr=0;
        for(i=0,j=n-1;i<n;i++,j--)
        {
            mxl=max(a[i],mxl);
            mxr=max(a[j],mxr);
            w[i]=min(w[i],mxl-a[i]);
            w[j]=min(w[j],mxr-a[j]);
        }
        
        for(i=0;i<n;i++)
            ans+=w[i];
        
        return ans;
    }
    */
    
    /*
    int trap(vector<int>& a) {
        int i,j,n=a.size();
        int w[n],mx;
        int ans=0;
        
        mx=0;
        for(i=0;i<n;i++)
        {
            mx=max(a[i],mx);
            w[i]=mx-a[i];
        }
        
        mx=0;
        for(i=n-1;i>=0;i--)
        {
            mx=max(a[i],mx);
            w[i]=min(w[i],mx-a[i]);
            ans+=w[i];
        }
        
        return ans;
    }
    */
    
    /*
    int trap(vector<int>& a) {
        int i,j,n=a.size();
        int l[n],r[n],mx;
        
        mx=0;
        for(i=0;i<n;i++)
        {
            mx=max(a[i],mx);
            l[i]=mx-a[i];
        }
        
        mx=0;
        for(i=n-1;i>=0;i--)
        {
            mx=max(a[i],mx);
            r[i]=mx-a[i];
        }
        
        int ans=0;
        for(i=0;i<n;i++)
            ans+=min(l[i],r[i]);
        
        return ans;
    }
    */
};