class Solution {
public:
    int minCostClimbingStairs(vector<int>& a) {
        int n=a.size(),i;
        
        int dp[n];
        dp[0]=a[0];
        dp[1]=a[1];
        
        for(i=2;i<n;i++)
            dp[i]=a[i]+min(dp[i-1],dp[i-2]);
        
        return min(dp[n-1],dp[n-2]);
    }
    
    /*
    int minCostClimbingStairs(vector<int>& a) {
        int n=a.size(),i;
        
        for(i=n-3;i>=0;i--)
            a[i]+=min(a[i+1],a[i+2]);
        
        return min(a[0],a[1]);
    }
    */
    
    /*
    int minCostClimbingStairs(vector<int>& a) {
        int n=a.size(),i;
        
        int dp[n+1];
        dp[n]=0;
        dp[n-1]=a[n-1];
        
        for(i=n-2;i>=0;i--)
            dp[i]=a[i]+min(dp[i+1],dp[i+2]);
        
        return min(dp[0],dp[1]);
    }
    */
};