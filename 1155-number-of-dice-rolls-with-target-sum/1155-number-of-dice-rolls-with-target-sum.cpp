class Solution {
public:
    int numRollsToTarget(int n, int k, int t) {
        vector<vector<int>> dp(n+1,vector<int>(t+1,0));
        int i,j,x;
        int m=1e9+7;
        dp[0][0]=1;
        
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=t;j++)
            {
                for(x=1;x<=k && x<=j;x++)
                {
                    dp[i][j]=(dp[i][j]+dp[i-1][j-x])%m;
                }
            }
        }
        
        return dp[n][t];
    }
    /*
    int m=1e9+7;
    
    int numRollsToTarget(int n, int k, int t,vector<vector<int>> &dp)
    {
        if(n==0 && t==0)
            return 0;
        
        if(n==0 || t==0 || t<n)
            return -1;
        
        if(t==n)
            return 1;
        
        if(n==1)
        {
            if(t<=k)
                return 1;
            return 0;
        }
        
        if(dp[n][t]==-1)
        {
            dp[n][t]=0;
            for(int i=1;i<=k && i<=t;i++)
            {
                int x=numRollsToTarget(n-1,k,t-i,dp);
                if(x==-1 || x==0)
                    continue;
                
                dp[n][t]=(dp[n][t]+x)%m;
            }
        }
        
        return dp[n][t];
    }
    
    int numRollsToTarget(int n, int k, int t) {
        vector<vector<int>> dp(n+1,vector<int>(t+1,-1));
        return numRollsToTarget(n,k,t,dp);
    }
    */
};