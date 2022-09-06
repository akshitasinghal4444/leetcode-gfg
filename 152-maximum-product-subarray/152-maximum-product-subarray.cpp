class Solution {
public:
    int maxProduct(vector<int>& a) {
        int l=1,r=1,ans=a[0];
        int j,i,n=a.size();
        
        for(i=0,j=n-1;i<n;i++,j--)
        {
            l*=a[i];
            r*=a[j];
            
            ans=max({ans,l,r});
            
            if(l==0)
                l=1;
            if(r==0)
                r=1;
        }
        
        return ans;
    }
};