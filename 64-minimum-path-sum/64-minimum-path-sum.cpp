class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        int i,j;
        
        for(i=m-1;i>=0;i--)
        {
            for(j=n-1;j>=0;j--)
            {
                if(i==m-1 && j==n-1)
                    continue;
                
                if(i==m-1)
                    a[i][j]+=a[i][j+1];
                else if(j==n-1)
                    a[i][j]+=a[i+1][j];
                else
                    a[i][j]+=min(a[i+1][j],a[i][j+1]);
            }
        }
        
        return a[0][0];
    }
};