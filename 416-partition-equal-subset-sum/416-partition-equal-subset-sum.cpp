class Solution {
public:
    bool canPartition(vector<int>& a)
    {
        int n=a.size(),s=0;
        int i,j;
        
        for(i=0;i<n;i++)
            s+=a[i];
        
        if(s%2!=0)
            return 0;
        
        s=s/2;
        
        bool dp[n+1][s+1];
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=s;j++)
            {
                if(j==0)
                    dp[i][j]=1;
                else if(i==0)
                    dp[i][j]=0;
                else if(a[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i-1]];
            }
        }
        return dp[n][s];
    }
    
    /*
     bool canPartition(vector<int>& a)
     {
         int j,i,n,sum=0;
         n=a.size();
         
         for(i=0;i<n;i++)
             sum+=a[i];
         
         if(sum%2!=0)
             return 0;
         
         sum=sum/2;
         bool dp[n+1][sum+1];

         for(i=0;i<=n;i++)
         {
             for(j=0;j<=sum;j++)
             {
                 if(j==0)
                     dp[i][j]=1;
                 else if(i==0)
                     dp[i][j]=0;
                 else
                 {
                     if(a[i-1]>j)
                         dp[i][j]=dp[i-1][j];
                     else
                         dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]];
                 }
             }
         }
         return dp[n][sum];
     }
    */
};