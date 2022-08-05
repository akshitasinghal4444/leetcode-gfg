class Solution {
public:
    int combinationSum4(vector<int>& a, int t) {
        int i,j,n=a.size();
        vector<unsigned int> dp(t+1,0);
        dp[0]=1;
        
        for(i=1;i<=t;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[j]>i)
                    continue;
                
                dp[i]+=dp[i-a[j]];
            }
        }
        
        return dp[t];
    }
};