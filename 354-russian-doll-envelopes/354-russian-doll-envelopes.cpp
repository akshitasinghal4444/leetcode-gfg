class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& env)
    {
        sort(env.begin(),env.end(),comp);
        
        int n=env.size(),i,j;
        vector<int> dp;
        dp.push_back(env[0][1]);
        
        for(i=1;i<n;i++)
        {
           if(env[i][1]>dp.back())
               dp.push_back(env[i][1]);
            else
            {
                j=lower_bound(dp.begin(),dp.end(),env[i][1])-dp.begin();
                dp[j]=env[i][1];
            }
        }
        return dp.size();
    }
    
   /* 
    static bool comp(vector<int> a,vector<int> b)
    {
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& env)
    {
        sort(env.begin(),env.end(),comp);
        int n=env.size(),i,j,ans=1;
        vector<int> dp(n,0);
        dp[0]=1;
        for(i=1;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(env[i][0]>env[j][0] && env[i][1]>env[j][1])
                    dp[i]=max(dp[i],dp[j]);
            }
            dp[i]++;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
    */
    
    /*
    int maxEnvelopes(vector<vector<int>>& E) {
        sort(E.begin(), E.end(), [](vector<int>& a, vector<int>& b) 
             -> bool {return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];});
        vector<int> dp;
        for (auto& env : E) {
            int height = env[1];
            int left = lower_bound(dp.begin(), dp.end(), height) - dp.begin();
            if (left == dp.size()) dp.push_back(height);
            dp[left] = height;
        }
        return dp.size();
    }
    */

};