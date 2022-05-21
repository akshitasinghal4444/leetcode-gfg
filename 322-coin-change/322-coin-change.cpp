class Solution {
public:
    int coinChange(vector<int>& a, int amt) {
        int n=a.size(),i,j;
        vector<int> dp(amt+1,INT_MAX);
        dp[0]=0;
        
        for(i=1;i<=amt;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i>=a[j] && dp[i-a[j]]!=INT_MAX)
                    dp[i]=min(dp[i],dp[i-a[j]]+1);
            }
        }
        return dp[amt]!=INT_MAX?dp[amt]:-1;
    }
};
