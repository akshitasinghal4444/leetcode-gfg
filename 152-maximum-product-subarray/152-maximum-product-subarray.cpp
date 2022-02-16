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
    
};