class Solution {
public:
    int maxProduct(vector<int>& a)
    {
        int lp=1,rp=1,ans=a[0];
        int n=a.size();
        int l=0,r=n-1;
        
        while(l<n)
        {
            lp*=a[l];
            rp*=a[r];
            
            ans=max(ans,max(lp,rp));
            
            if(lp==0)
                lp=1;
            if(rp==0)
                rp=1;
            
            l++;
            r--;
        }
        return ans;
    }
    
    /*
    int maxProduct(vector<int>& a) {
        int n=a.size();
        int l=0,r=n-1,mp=a[0],p1=1,p2=1;
        if(n==1)
            return a[0];
        
        while(l<n)
        {
            if(p1==0)
                p1=1;
            if(p2==0)
                p2=1;
            p1*=a[l];
            p2*=a[r];
            mp=max(mp,p1);
            mp=max(mp,p2);
            r--;
            l++;
        }
        
        return mp;
    }
    */
};