class Solution {
public:
    int deleteAndEarn(vector<int>& a) {
        int n=a.size();
        int i,ans=0;
        
        int mn=a[0],mx=a[0];
        for(i=0;i<n;i++)
        {
            mx=max(mx,a[i]);
            mn=min(mn,a[i]);
        }
        
        vector<int> dp(mx-mn+1,0);
        for(i=0;i<n;i++)
        {
            dp[a[i]-mn]+=a[i];
        }
        
        n=mx-mn+1;
        if(n>1)
        dp[1]=max(dp[0],dp[1]);
        for(i=2;i<n;i++)
        {
            dp[i]=max(dp[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }
};