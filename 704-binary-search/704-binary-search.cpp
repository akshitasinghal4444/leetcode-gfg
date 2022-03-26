class Solution {
public:
    int search(vector<int>& a, int t) {
        int l=0,r=a.size()-1;
        int i;
        
        while(l<=r)
        {
            int mid=(l+r)/2;
            
            if(a[mid]==t)
                return mid;
            
            if(a[mid]<t)
                l=mid+1;
            else
                r=mid-1;
        }
        
        return -1;
    }
};