class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t)
    {
        int m=a.size(),n=a[0].size();
        int l,r,i,j,mid;
        
        l=0,r=m-1;
        
        while(l<=r)
        {
            if(t<a[l][0] || t>a[r][n-1])
                return 0;
            
            mid=(l+r)/2;
            
            if(t>=a[mid][0] && t<=a[mid][n-1])
                break;
            
            if(t<a[mid][0])
                r=mid-1;
            else
                l=mid+1;
        }
        
        if(l>r)
            return 0;
        
        i=mid;
        l=0,r=n-1;
        // cout<<l<<" "<<r<<endl;
        while(l<=r)
        {
            mid=(l+r)/2;
            
            // cout<<mid<<endl;
            if(t==a[i][mid])
                return 1;
            
            if(t>a[i][mid])
                l=mid+1;
            else
                r=mid-1;
        }
        
        return 0;
    }
    
    /*
    bool searchMatrix(vector<vector<int>>& a, int t) {
        
        int m=a.size(),n=a[0].size();
        int i=0,j=n-1;
        
        while(i<m && j>=0)
        {
            if(a[i][j]==t)
                return 1;
            
            if(a[i][j]<t)
                i++;
            else
                j--;
        }
        
        return 0;
    }
    */
};