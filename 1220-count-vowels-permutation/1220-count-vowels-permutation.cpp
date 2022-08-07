class Solution {
public:
    int countVowelPermutation(int n)
    {
        int m=1e9+7;
        int j;
        long ans=0;
        long dp[5][n+1];
        
        dp[0][1]=1,dp[1][1]=1,dp[2][1]=1,dp[3][1]=1,dp[4][1]=1;
        
        for(j=2;j<=n;j++)
        {
            dp[0][j]=(dp[1][j-1]+dp[2][j-1]+dp[4][j-1])%m;
            dp[1][j]=(dp[0][j-1]+dp[2][j-1])%m;
            dp[2][j]=(dp[1][j-1]+dp[3][j-1])%m;
            dp[3][j]=dp[2][j-1]%m;
            dp[4][j]=(dp[2][j-1]+dp[3][j-1])%m;
        }
        
        for(j=0;j<5;j++)
            ans=(ans+dp[j][n])%m;
        
        return ans;
    }
    
    /*
    int countVowelPermutation(int n) {
        if(n==1)
            return 5;
        
        vector<vector<long>> dp(5,vector<long>(n+1));
        
        int i,j;
        int m=1e9+7;
        
        for(j=1;j<=n;j++)
        {
            for(i=0;i<5;i++)
            {
                if(j==1)
                    dp[i][j]=1;
                else 
                {
                    if(i==0)
                        dp[i][j]=(dp[1][j-1]+dp[2][j-1]+dp[4][j-1])%m;
                    else if(i==1)
                        dp[i][j]=(dp[0][j-1]+dp[2][j-1])%m;
                    else if(i==2)
                        dp[i][j]=(dp[1][j-1]+dp[3][j-1])%m;
                    else if(i==3)
                        dp[i][j]=dp[2][j-1]%m;
                    else if(i==4)
                        dp[i][j]=(dp[2][j-1]+dp[3][j-1])%m;
                }
            }
        }
        
        long ans=0;
        for(i=0;i<5;i++)
            ans=(ans+dp[i][n])%m;
        
        return ans;
    }
    */
};