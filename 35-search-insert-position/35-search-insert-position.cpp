class Solution {
public:
    int searchInsert(vector<int>& a, int t) {
        int l=0,h=a.size()-1;
        int ans=h+1;
        
        while(l<=h)
        {
            int mid=(l+h)/2;
            
            if(a[mid]==t)
                return mid;
            
            if(a[mid]>t)
            {
                ans=mid;
                h=mid-1;
            }
            else
                l=mid+1;
        }
        
        return ans;
    }
};