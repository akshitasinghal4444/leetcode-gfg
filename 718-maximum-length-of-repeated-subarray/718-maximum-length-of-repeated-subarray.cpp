class Solution {
public:
    int findLength(vector<int>& a1, vector<int>& a2) {
        int n1=a1.size(),n2=a2.size();
        int i,j;
        int ans=0;
        int dp[n1+1][n2+1];
        
        if(n1==0 || n2==0)
            return 0;
        
        for(i=0;i<=n1;i++)
            dp[i][n2]=0;
        
        for(j=0;j<=n2;j++)
            dp[n1][j]=0;
        
        for(j=n2-1;j>=0;j--)
        {
            for(i=0;i<n1;i++)
            {
                if(a1[i]==a2[j])
                    dp[i][j]=1+dp[i+1][j+1];
                else
                    dp[i][j]=0;
                
                ans=max(ans,dp[i][j]);
            }
        }
        
        return ans;
    }
};