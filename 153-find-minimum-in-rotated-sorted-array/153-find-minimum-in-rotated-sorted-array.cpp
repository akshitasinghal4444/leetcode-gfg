class Solution {
public:
    int findMin(vector<int>& a)
    {
        int l=0,r=a.size()-1,mid;
        
        while(l<=r)
        {
            mid=(l+r)/2;
            
            if(a[mid]>=a[r])
                l=mid+1;
            else
                r=mid;
        }
        return a[mid];
    }
    
    /*
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
    */
    
    /*
    int binSearch(vector<int>& a,int l,int h)
    {
        int ans=INT_MAX;
        while(l<=h)
        {
            int mid=(l+h)/2;
            ans=min(ans,a[mid]);
            if(a[mid]>a[h])
                l=mid+1;
            else
                h=mid-1;               
        }
        return ans;
    }
    
    int findMin(vector<int>& a) {
        int n=a.size();
        return binSearch(a,0,n-1);
    }
    
    */
};