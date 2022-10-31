class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        int i,j,k;
        
        for(k=0;k<n;k++)
        {
            int x=a[0][k];
            for(i=0,j=k;i<m && j<n;i++,j++)
            {
                if(a[i][j]!=x)
                    return 0;
            }
        }
        
        for(k=0;k<m;k++)
        {
            int x=a[k][0];
            for(i=k,j=0;i<m && j<n;i++,j++)
            {
                if(a[i][j]!=x)
                    return 0;
            }
        }
        
        return 1;
    }
};