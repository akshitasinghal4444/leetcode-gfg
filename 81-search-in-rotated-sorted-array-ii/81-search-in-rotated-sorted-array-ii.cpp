class Solution {
public:
    bool search(vector<int>& a, int t) {
        int l=0,r=a.size()-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            
            if(a[mid]==t || a[l]==t || a[r]==t)
                return 1;
            
            if(a[l]==a[r])
            {
                l++;
                r--;
            }
            else if(a[mid]<=a[r])
            {
                if(t>a[mid] && t<=a[r])
                    l=mid+1;
                else
                    r=mid-1;
            }
            else
            {
                if(t>=a[l] && t<a[mid])
                    r=mid-1;
                else
                    l=mid+1;
            }
        }
        
        return 0;
    }
};

/*
 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18
[1,1,1,1,1,1,1,1,1,1,1 , 1,1 , 2,1 , 1,1 ,1 ,1]
2
*/