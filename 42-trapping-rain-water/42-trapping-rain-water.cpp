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
};