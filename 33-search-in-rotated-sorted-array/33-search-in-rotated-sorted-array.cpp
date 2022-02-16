class Solution {
public:
    int search(vector<int>& a, int t)
    {
        int l=0,r=a.size()-1;
        
        while(l<=r)
        {
            int mid=(l+r)/2;
            
            if(a[mid]==t)
                return mid;
            
            if(a[mid]<=a[r])
            {
                if(t>=a[mid] && t<=a[r])
                    l=mid+1;
                else
                    r=mid-1;
            }
            else
            {
                if(t>=a[l] && t<=a[mid])
                    r=mid-1;
                else
                    l=mid+1;
            }
        }
        return -1;
    }
    
    /*
    int search(vector<int>& a, int t) {
        int l=0,h=a.size()-1;
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
    */
};