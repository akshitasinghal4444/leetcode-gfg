class Solution {
public:
    
    int twoCitySchedCost(vector<vector<int>>& cost)
    {
        int n=cost.size(),i;
        vector<int> diff;
        int ans=0;
        
        for(i=0;i<n;i++)
        {
            ans+=cost[i][0];
            diff.push_back(cost[i][1]-cost[i][0]);
        }
        
        sort(diff.begin(),diff.end());
        
        for(i=0;i<n/2;i++)
            ans+=diff[i];
        
        return ans;
    }
    
   /* 
    int mincost(vector<vector<int>>& cost,int in,int a,int b,vector<vector<vector<int>>> &dp)
    {
        if(a==0 && b==0)
            return 0;
        
        if(dp[in][a][b]==INT_MAX)
        {
            if(a>0)
                dp[in][a][b]=min(dp[in][a][b],cost[in][0]+mincost(cost,in+1,a-1,b,dp));
        
            if(b>0)
                dp[in][a][b]=min(dp[in][a][b],cost[in][1]+mincost(cost,in+1,a,b-1,dp));
        
        }
        
        return dp[in][a][b];
    }
    
    int twoCitySchedCost(vector<vector<int>>& cost) {
        int n=cost.size();

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n/2+1,vector<int> (n/2+1,INT_MAX)));
        
        return mincost(cost,0,n/2,n/2,dp);
    }
    */
};