class Solution {
public:
    int trap(vector<int>& a) {
        
        int l=0,r=a.size()-1;
        int lmax=a[l],rmax=a[r];
        int ans=0;
        
        while(l<=r)
        {
            lmax=max(a[l],lmax);
            rmax=max(a[r],rmax);
            
            if(lmax<=rmax)
                ans+=(lmax-a[l++]);
            else
                ans+=(rmax-a[r--]);
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