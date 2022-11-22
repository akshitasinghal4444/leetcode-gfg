class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        int i,j;
        dp[0]=0;

        for(i=1;i*i<=n;i++)
        {
            for(j=i*i;j<=n;j++)
            {
                dp[j]=min(dp[j],dp[j-i*i]+1);
            }
        }
        
        return dp[n];
    }
};