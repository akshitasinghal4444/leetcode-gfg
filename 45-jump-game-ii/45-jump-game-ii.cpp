class Solution {
public:
    int jump(vector<int>& a) {
        int i,j,n=a.size();
        vector<int> dp(n,INT_MAX);
        dp[0]=0;
        
        for(i=0;i<n-1;i++)
        {
            if(dp[i]==INT_MAX)
                continue;
            
            for(j=1;j<=a[i] && i+j<n;j++)
            {
                dp[i+j]=min(dp[i+j],dp[i]+1);
                if(i+j==n-1)
                    return dp[n-1];
            }
                
        }
        
        return dp[n-1];
    }
};