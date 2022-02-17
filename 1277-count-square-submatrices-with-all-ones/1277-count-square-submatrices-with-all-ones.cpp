class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        int m,n,i,j;
        m=a.size();
        n=a[0].size();
        int dp[m][n];
        
        int c=0;
        
        for(i=m-1;i>=0;i--)
        {
            for(j=n-1;j>=0;j--)
            {
                if(i==m-1 || j==n-1)
                    dp[i][j]=a[i][j];
                else if(a[i][j])
                    dp[i][j]=1+min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1]));
                else
                    dp[i][j]=0;
                
                c+=dp[i][j];
            }
        }
        
        return c;
    }
};