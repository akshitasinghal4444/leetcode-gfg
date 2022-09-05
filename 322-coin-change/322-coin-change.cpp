class Solution {
public:
    int coinChange(vector<int>& a, int t) {
        int n=a.size();
        int i,j;
        vector<int> dp(t+1,INT_MAX);
        dp[0]=0;
        
        for(i=1;i<=t;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i>=a[j] && dp[i-a[j]]!=INT_MAX)
                    dp[i]=min(dp[i],dp[i-a[j]]+1);
            }
        }
        
        return dp[t]==INT_MAX?-1:dp[t];
    }
};