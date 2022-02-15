class Solution {
public:
    int minCostClimbingStairs(vector<int>& a)
    {
        int n=a.size();
        int dp[n+1];
        dp[0]=0;
        dp[1]=0;
        
        for(int i=2;i<=n;i++)
        {
            dp[i]=min(dp[i-1]+a[i-1],dp[i-2]+a[i-2]);
        }
        
        return dp[n];
    }
    
    /*
    int minCostClimbingStairs(vector<int>& a) {
        int n=a.size();
        int i,j;
        int dp[n+1];
        dp[n]=0;
        for(i=n-1;i>=0;i--)
        {
            if(i==n-1)
            dp[i]=dp[i+1]+a[i];
            else
                dp[i]=min(dp[i+1],dp[i+2])+a[i];
        }
        return min(dp[0],dp[1]);
    }
    */
};