class Solution {
public:
     vector<int> searchRange(vector<int>& a, int t)
     {
         if(a.size()==0)
             return {-1,-1};
         
         int st=lower_bound(a.begin(),a.end(),t)-a.begin();
         int end=upper_bound(a.begin(),a.end(),t)-a.begin();
         
         if(end==0 || a[end-1]!=t)
             return {-1,-1};
         
         return {st,end-1};
     }
    
    /*
    vector<int> searchRange(vector<int>& a, int t) {
        int n=a.size();
        int l=0,r=n-1,mid;
        
        while(l<=r)
        {
            mid=(l+r)/2;
            
            if(a[mid]==t)
                break;
            
            if(a[mid]<t)
                l=mid+1;
            else
                r=mid-1;
        }
        
        if(l>r)
            return {-1,-1};
        
        int st=mid,end=mid;
        
        while(st>=l && a[st]==t)
            st--;
        
        while(end<=r && a[end]==t)
            end++;
        
        return {st+1,end-1};
    }
    */
};