class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        int i,j,ans=1;
        vector<int> dp(n,0);
        dp[0]=1;
        
        for(i=1;i<n;i++)
        {
            for(j=i-1;j>=0;j--)
            {
                if(a[i]>a[j])
                    dp[i]=max(dp[i],dp[j]);
            }
            
            dp[i]++;
            ans=max(ans,dp[i]);
        }
        
        return ans;
    }
};