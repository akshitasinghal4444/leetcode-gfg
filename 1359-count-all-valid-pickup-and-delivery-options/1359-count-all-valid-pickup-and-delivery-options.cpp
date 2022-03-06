class Solution {
public:
    int countOrders(int n) {
        int m=1e9+7;
        long dp[n+1];
        dp[1]=1;
        
        int i;
        for(i=2;i<=n;i++)
        {
            int x=2*i-1;
            dp[i]=(dp[i-1]*(x*(x+1)/2)%m)%m;
        }
        return dp[n];
    }
};