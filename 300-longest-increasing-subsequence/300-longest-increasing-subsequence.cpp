class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        vector<int> dp(n);
        int i,j;
        int ans=1;
        
        dp[0]=1;
        
        for(i=1;i<n;i++)
        {
            int mx=0;
            
            for(j=0;j<i;j++)
            {
                if(a[i]>a[j])
                    mx=max(mx,dp[j]);
            }
            
            dp[i]=mx+1;
            ans=max(ans,dp[i]);
            
        }
        return ans;
    }
};