class Solution {
public:
    
    int lengthOfLIS(vector<int>& a)
    {
        int n=a.size();
        int i;
        
        vector<int> seq;
        seq.push_back(a[0]);
        
        for(i=1;i<n;i++)
        {
            if(a[i]>seq.back())
                seq.push_back(a[i]);
            else
            {
                int in=(lower_bound(seq.begin(),seq.end(),a[i]))-seq.begin();
                seq[in]=a[i];
            }
        }
        return seq.size();
    }
    
    /*
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
    */
};