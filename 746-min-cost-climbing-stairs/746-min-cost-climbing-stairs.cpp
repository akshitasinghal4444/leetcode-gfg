class Solution {
public:
    int minCostClimbingStairs(vector<int>& a)
    {
        int i,n=a.size();
        
        for(i=2;i<n;i++)
            a[i]=min(a[i-1],a[i-2])+a[i];
        
        return min(a[i-1],a[i-2]);
    }
    
    /*
    int minCostClimbingStairs(vector<int>& a) {
        int i,n=a.size();
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=0;
        
        for(i=2;i<=n;i++)
            dp[i]=min(dp[i-1]+a[i-1],dp[i-2]+a[i-2]);
        
        return dp[n];
    }
    */
};