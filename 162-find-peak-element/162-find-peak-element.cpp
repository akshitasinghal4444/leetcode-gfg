class Solution {
public:
    int findPeakElement(vector<int>& a,int l,int r)
    {
        if(l>r)
            return -1;
        
        int ans=-1;
        int mid=(l+r)/2;
            
        if((mid>0 && a[mid-1]>=a[mid]))
            ans=findPeakElement(a,l,mid-1);
        else if(mid<a.size()-1 && a[mid+1]>=a[mid])
            ans=findPeakElement(a,mid+1,r);
        else 
            ans=mid;
        
        // cout<<l<<" "<<r<<" "<<ans<<endl;
        return ans;
    }
    
    int findPeakElement(vector<int>& a) {
        return findPeakElement(a,0,a.size()-1);
    }
    
    /*
    int findPeakElement(vector<int>& a,int l,int r)
    {
        if(l>r)
            return -1;
        
        int ans=-1;
        int mid=(l+r)/2;
            
        if((mid>0 && a[mid-1]>=a[mid])||(mid<a.size()-1 && a[mid+1]>=a[mid]))
        {
                ans=findPeakElement(a,l,mid-1);
                
                if(ans==-1)
                    ans=findPeakElement(a,mid+1,r);
        }
        else 
            ans=mid;
        
        // cout<<l<<" "<<r<<" "<<ans<<endl;
        return ans;
    }
    
    int findPeakElement(vector<int>& a) {
        return findPeakElement(a,0,a.size()-1);
    }
    */
};