class Solution {
public:
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
};