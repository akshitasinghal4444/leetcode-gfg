class Solution {
public:
    int jump(vector<int>& a)
    {
        int n=a.size();
        if(n==1)
            return 0;
        
        int j=0,curr_reach=0,max_reach=0;
        int i;
        
        for(i=0;i<n-1;i++)
        {
            max_reach=max(max_reach,i+a[i]);
            // if(max_reach>=n-1)
            //     return j+1;
            
            if(i==curr_reach)
            {
                curr_reach=max_reach;
                j++;
            }
        }
        return j;
    }
    
    /*
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
            }
        }
        return dp[n-1];
    }
    */
    
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