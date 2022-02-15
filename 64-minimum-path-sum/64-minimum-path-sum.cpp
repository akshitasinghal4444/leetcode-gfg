class Solution {
public:
    
    int minPathSum(vector<vector<int>>& a)
    {
        int m,n,i,j;
        m=a.size();
        n=a[0].size();
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    continue;
                
                if(i==0)
                    a[i][j]+=a[i][j-1];
                else if(j==0)
                    a[i][j]+=a[i-1][j];
                else
                    a[i][j]+=min(a[i][j-1],a[i-1][j]);
                    
            }
        }
        return a[m-1][n-1];
    }
    
    /*
    int minPathSum(vector<vector<int>>& a) {
        int m,n;
        m=a.size();
        n=a[0].size();
        
        int i,j;
        for(i=m-1;i>=0;i--)
        {
            for(j=n-1;j>=0;j--)
            {
                if(i==m-1 && j==n-1)
                    a[i][j]=a[i][j];
                else if(i==m-1)
                    a[i][j]+=a[i][j+1];
                else if(j==n-1)
                    a[i][j]+=a[i+1][j];
                else
                {
                    a[i][j]+=min(a[i][j+1],a[i+1][j]);
                }
                    
            }
        }
        return a[0][0];
    }
    */
};