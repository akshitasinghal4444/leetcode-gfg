class Solution {
public:
    int lengthOfLIS(vector<int>& a)
    {
        int i,n=a.size();
        vector<int> dp;
        
        for(i=0;i<n;i++)
        {
            if(dp.size()==0 || a[i]>dp.back())
                dp.push_back(a[i]);
            else
            {
                int j=lower_bound(dp.begin(),dp.end(),a[i])-dp.begin();
                dp[j]=a[i];
            }
        }
        
        return dp.size();
    }
    
    /*
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
    */
};