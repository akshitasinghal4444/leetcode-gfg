class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t)
    {
        int m=a.size(),n=a[0].size();
        int i,j;
        int l,r,mid;
        
        if(t<a[0][0] || t>a[m-1][n-1])
            return 0;
        
        l=0,r=m-1;
        
        while(l<=r)
        {
            mid=(l+r)/2;
            
            if(a[mid][0]==t)
                return 1;
            
            if(a[mid][0]>t)
                r=mid-1;
            else if(a[mid][0]<t && a[mid][n-1]>=t)
                break;
            else
                l=mid+1;
        }
        
        l=0,r=n-1,i=mid;
        
        while(l<=r)
        {
            mid=(l+r)/2;
            
            if(a[i][mid]==t)
                return 1;
            
            if(a[i][mid]<t)
                l=mid+1;
            else
                r=mid-1;
        }
        
        return 0;
    }
    
    
    /*
    int binSearch(vector<int> &a,int k)
    {
        int l=0,h=a.size()-1,mid;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(a[mid]==k)
                return mid;
            if(a[mid]<k)
                l=mid+1;
            else
                h=mid-1;
        }
        return -1;
    }
    
    bool searchMatrix(vector<vector<int>>& a, int t) {
        int m=a.size();
        int n=a[0].size();
        int i=0;
        while(i<m)
        {
            if(a[i][n-1]<t)
            {
                i++;
                continue;
            }
            if(a[i][0]>t)
                return 0;
            int ind=binSearch(a[i],t);
            if(ind==-1)
                return 0;
            else
                return 1;
        }
        return 0;
    }
    */
};