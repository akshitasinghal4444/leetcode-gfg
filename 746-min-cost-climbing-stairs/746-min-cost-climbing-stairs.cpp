class Solution {
public:
    int minCostClimbingStairs(vector<int>& a) {
        int n=a.size(),i;
        
        int dp[n+1];
        dp[n]=0;
        dp[n-1]=a[n-1];
        
        for(i=n-2;i>=0;i--)
            dp[i]=a[i]+min(dp[i+1],dp[i+2]);
        
        return min(dp[0],dp[1]);
    }
};