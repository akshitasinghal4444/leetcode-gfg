class Solution {
public:
    int lengthOfLIS(vector<int>& a)
    {
        vector<int> dp;
        
        for(int x:a)
        {
            if(dp.empty() || dp.back()<x)
                dp.push_back(x);
            else
            {
                int i=lower_bound(dp.begin(),dp.end(),x)-dp.begin();
                dp[i]=x;
            }
        }
        
        return dp.size();
    }
    
    /*
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        int i,j,ans=1;
        int dp[n];
        
        for(i=0;i<n;i++)
        {
            int mx=0;
            for(j=i-1;j>=0;j--)
            {
                if(a[j]<a[i])
                    mx=max(mx,dp[j]);
            }
                    
            dp[i]=mx+1;
            ans=max(ans,dp[i]);
        }
        
        return ans;
    }
    */
};