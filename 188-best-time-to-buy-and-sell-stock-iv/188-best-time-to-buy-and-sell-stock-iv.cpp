class Solution {
public:
    int maxProfit(int k, vector<int>& a)
    {
        int i,j;
        int n=a.size();
        
        if(k==0 || n==0)
            return 0;
        
        int dp[k+1][n];
        
        for(i=0;i<=k;i++)
        {
            int mx=INT_MIN;
            for(j=0;j<n;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else
                {
                    mx=max(mx,dp[i-1][j-1]-a[j-1]); 
                    dp[i][j]=max(dp[i][j-1],mx+a[j]);  
                }
            }
        }
        return dp[k][n-1];
    }
    
    /*
    int maxProfit(int k, vector<int>& a) {
        int n=a.size();
        
        if(n==0 || k==0)
            return 0;
        
        int dp[k+1][n];
        int i,j;
        
        for(i=0;i<=k;i++)
        {
            int mx=INT_MIN;
            for(j=0;j<n;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else
                {
                    mx=max(mx,dp[i-1][j-1]-a[j-1]);
                    dp[i][j]=max(dp[i][j-1],a[j]+mx);
                }
            }
        }
        return dp[k][n-1];
    }
    */
};