class Solution {
public:
    
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
    
    /*
    int mincost(vector<vector<int>>& cost,int in,int a,int b)
    {
        if(a==0 && b==0)
            return 0;
        
        int x=INT_MAX;
        
        if(a>0)
            x=min(x,cost[in][0]+mincost(cost,in+1,a-1,b));
        
        if(b>0)
            x=min(x,cost[in][1]+mincost(cost,in+1,a,b-1));
        
        return x;
        
    }
    
    int twoCitySchedCost(vector<vector<int>>& cost) {
        int n=cost.size();

        return mincost(cost,0,n/2,n/2);
    }
    */
};