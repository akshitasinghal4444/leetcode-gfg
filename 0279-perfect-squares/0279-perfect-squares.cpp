class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        int i,j;
        dp[0]=0;
        
        for(i=1;i<=n;i++)
            dp[i]=i;
        
        for(i=2;i*i<=n;i++)
        {
            for(j=i*i;j<=n;j++)
            {
                dp[j]=min(dp[j],dp[j-i*i]+1);
            }
        }
        
        return dp[n];
    }
};