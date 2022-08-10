class Solution {
public:
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
};