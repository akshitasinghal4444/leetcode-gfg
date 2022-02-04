class Solution {
public:
    int jump(vector<int>& a) {
        int n=a.size();
        vector<int> dp(n,INT_MAX);
        dp[0]=0;
        int i,j;
        
        for(i=0;i<n-1;i++)
        {
            for(j=min(i+a[i],n-1);j>i;j--)
            {
                if(dp[j]>dp[i]+1)
                    dp[j]=dp[i]+1;
                else
                    break;
                
                if(j==n-1)
                    return dp[j];
            }
        }
        return dp[n-1];
    }
    
    /*
    int jump(vector<int>& a) {
        int n=a.size();
        vector<int> dp(n,INT_MAX);
        dp[n-1]=0;
        int i,j;
        
        for(i=n-2;i>=0;i--)
        {
            for(j=1;j<=a[i] && j+i<n;j++)
            {
                if(dp[i+j]!=INT_MAX)
                dp[i]=min(dp[i],dp[i+j]+1);
            }
        }
        return dp[0];
    }
    */
};