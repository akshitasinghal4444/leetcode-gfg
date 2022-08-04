class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t)
    {
        int m=a.size(),n=a[0].size();
        int l=0,r=m-1,mid;
        
        if(t<a[0][0] || t>a[m-1][n-1])
            return 0;
        
        while(l<=r)
        {
            mid=(l+r)/2;
            
            if(a[mid][0]==t)
                return 1;
            
            if(a[mid][0]>t)
                r=mid-1;
            else if(t>=a[mid][0] && t<=a[mid][n-1])
                break;
            else
                l=mid+1;
        }
        
        if(t<a[mid][0] || t>a[mid][n-1])
            return 0;
        
        l=0,r=n-1;
        int i=mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            
            if(a[i][mid]==t)
                return 1;
            
            if(t<a[i][mid])
                r=mid-1;
            else
                l=mid+1;
        }
        
        return 0;
    }
    
    /*
    bool searchMatrix(vector<vector<int>>& a, int t) {
        int i,j,m=a.size(),n=a[0].size();
        
        i=0,j=n-1;
        
        while(i<m && j>=0)
        {
            if(t==a[i][j])
                return 1;
            
            if(t>a[i][j])
                i++;
            else
                j--;
        }
        
        return 0;
    }
    */
};