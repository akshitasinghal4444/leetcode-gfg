class Solution {
public:
    int findMin(vector<int>& a)
    {
        int l=0,r=a.size()-1;
        if(a[l]<a[r])
            return a[l];
        
        while(l<r)
        {
            int mid=(l+r)/2;
            
            if(a[mid]>a[mid+1])
                return a[mid+1];
            
            if(a[mid-1]>a[mid])
                return a[mid];
            
            if(a[mid]>a[l])
                l=mid+1;
            else
                r=mid-1;
        }
        
        return a[0];
    }
    
    /*
    int findMin(vector<int>& a) {
        int ans=a[0];
        int l=0,r=a.size()-1;
        
        while(l<=r)
        {
            int mid=(l+r)/2;
            ans=min(ans,a[mid]);
            
            if(a[mid]<=a[r])
                r=mid-1;
            else
                l=mid+1;
        }
        
        return ans;
    }
    */
    
    /*
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
    */
};