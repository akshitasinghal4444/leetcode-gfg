class Solution {
public:
    
    int coinChange(vector<int>& a, int amt)
    {
        int n=a.size();
        int i,j;
        
        vector<int> dp(amt+1,INT_MAX);
        dp[0]=0;
        
        for(i=0;i<n;i++)
        {
            for(j=1;j<=amt;j++)
            {
                if(a[i]<=j && dp[j-a[i]]!=INT_MAX)
                {
                    dp[j]=min(dp[j],dp[j-a[i]]+1);
                }
            }
        }
        
        if(dp[amt]==INT_MAX)
            return -1;
        
        return dp[amt];
    }
    
  /*  
    int count(vector<int>& a,int n,int k)
    {
        if(k==0)
            return 0;
        if(n==0)
            return INT_MAX;
        int x=k/a[n-1];
        return min(count(a,n-1,k),count(a,n-1,k-x*a[n-1])!=INT_MAX?x+count(a,n-1,k-x*a[n-1]):INT_MAX);
    }
        
    int coinChange(vector<int>& a, int t) {
        int n=a.size();
        int c=count(a,n,t);
        if(c==INT_MAX)
            return -1;
        return c;
    }
    */

};