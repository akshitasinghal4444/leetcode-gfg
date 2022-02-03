class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n=a.size();
        int l=0,h=n-1;
        
        while(l<=h)
        {
            int mid=(l+h)/2;
            
            // cout<<l<<" "<<mid<<" "<<h<<endl;
            if(mid!=0 && a[mid]==a[mid-1])
            {
                if((mid-0)%2==0)
                    h=mid-1;
                else
                    l=mid+1;
            }
            else if(mid!=n-1 && a[mid]==a[mid+1])
            {
                if((n-1-mid)%2==0)
                    l=mid+1;
                else
                    h=mid-1;
            }
            else
                return a[mid];
        }
        
        return -1;
    }
};