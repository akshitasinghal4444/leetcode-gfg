class Solution {
public:
    int findMin(vector<int>& a) {
        int ans=a[0];
        int l=0,r=a.size()-1;
        
        while(l<=r)
        {
            int mid=(l+r)/2;
            
            if(a[mid]>=a[l])
            {
                ans=min(ans,a[l]);
                l=mid+1;
            }
            else
            {
                ans=min(ans,a[mid]);
                r=mid-1;
            }
        }
        
        return ans;
    }
};