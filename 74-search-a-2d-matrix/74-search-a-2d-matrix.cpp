class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t)
    {
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
    
    /*
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
        
        if(t<a[i][0] || t>a[i][n-1])
            return 0;
        
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
    */
    
    /*
    bool binSearch(vector<int> &a,int k)
    {
        int l=0,r=a.size()-1,mid;
        
        while(l<=r)
        {
            mid=(l+r)/2;
            
            if(a[mid]==k)
                return 1;
            
            if(a[mid]<k)
                l=mid+1;
            else
                r=mid-1;
        }
        return 0;
    }
    
    bool searchMatrix(vector<vector<int>>& a, int t) {
        int m=a.size();
        int n=a[0].size();
        int i=0;
        while(i<m)
        {
            if(a[i][n-1]<t)
                i++;
            else if(a[i][0]>t)
                return 0;
            else
                return binSearch(a[i],t);
        }
        return 0;
    }
    */
    
    

};