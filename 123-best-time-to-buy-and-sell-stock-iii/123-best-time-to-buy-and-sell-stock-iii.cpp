class Solution {
public:
    /*
    int maxProfit(vector<int>& a)
    {
        int i,n=a.size(),ans=0;
        int maxpl[n],maxpr[n];
        maxpl[0]=0;
        
        int mn=a[0];
        for(i=1;i<n;i++)
        {
            mn=min(mn,a[i]);
            maxpl[i]=max(maxpl[i-1],a[i]-mn);
        }
        
        int mx=a[n-1];
        maxpr[n-1]=0;
        for(i=n-2;i>=0;i--)
        {
            mx=max(mx,a[i]);
            maxpr[i]=max(maxpr[i+1],mx-a[i]);
            
            ans=max(ans,maxpl[i]+maxpr[i]);
        }
        return ans;
    }
    */
    
    int maxProfit(vector<int>& a)
    {
        int i,n=a.size();
        int fb=-a[0],fs=INT_MIN,sb=INT_MIN,ss=INT_MIN;
        
        for(i=1;i<n;i++)
        {
            fb=max(fb,-a[i]);
            fs=max(fs,fb+a[i]);
            
            sb=max(sb,fs-a[i]);
            ss=max(ss,sb+a[i]);
        }
        
        return max(ss,0);
    }
    
    /*
    int maxProfit(vector<int>& a)
    {
        int n=a.size();
        int i,fb=INT_MAX,sb=INT_MAX,fp=0,sp=0;
        
        for(i=0;i<n;i++)
        {
            fb=min(fb,a[i]);
            fp=max(fp,a[i]-fb);
            
            sb=min(sb,a[i]-fp);
            sp=max(sp,a[i]-sb);
        }
        
        return sp;
    }
    */
    
    /*
    int maxProfit(vector<int>& a) {
        int n=a.size();
        int i,mn=INT_MAX,mx=INT_MIN,ans=0,maxr=0;
        vector<int> maxp(n,0);
        
        for(i=0;i<n;i++)
        {
            mn=min(mn,a[i]);
            
            if(i==0)
                maxp[i]=a[i]-mn;
            else
                maxp[i]=max(maxp[i-1],a[i]-mn);
        }
        
        for(i=n-1;i>=0;i--)
        {
            mx=max(mx,a[i]);
            maxr=max(maxr,mx-a[i]);
            maxp[i]+=maxr;
        }
        
        for(i=0;i<n;i++)
        {
            ans=max(ans,maxp[i]);
        }
        
        return ans;
    }
    */
    
    
};