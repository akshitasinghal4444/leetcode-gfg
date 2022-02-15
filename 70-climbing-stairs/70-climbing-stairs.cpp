class Solution {
public:
    int climbStairs(int n)
    {
        if(n==0)
            return 0;
        
        int dp[n+1];
        dp[0]=1;
        dp[1]=1;
        
        int i;
        for(i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    
    /*
    int climbStairs(int n) {
        if(n<=1)
            return n;
        int a=0,b=1,c,i=2;
        for(i=2;i<=n+1;i++)
        {
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
    */
};