class Solution {
public:
    int search(vector<int>& a, int t) {
        int n=a.size();
        int l=0,h=n-1;
        while(l<=h)
        {
        
            int mid=(l+h)/2;
            if(a[mid]==t)
                return mid;
            
            if(a[l]<=a[mid])
            {
                if(t>=a[l] && t<a[mid])
                    h=mid-1;
                else
                    l=mid+1;
            }
            else
            {
                if(t>a[mid] && t<=a[h])
                    l=mid+1;
                else
                    h=mid-1;
            }
        }
        return -1;
    }
};