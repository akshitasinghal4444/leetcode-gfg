class Solution {
public:
    
    int cost(vector<int>& a,int l,int r,vector<vector<int>> &dp)
    {
        if(l>r)
            return 0;
        
        if(dp[l][r]==INT_MAX)
        {
            for(int i=l;i<=r;i++)
            {
                int lc=cost(a,l,i-1,dp);
                int rc=cost(a,i+1,r,dp);
                
                dp[l][r]=min(dp[l][r],lc+rc+a[r+1]-a[l-1]);
            }            
        }
                
        return dp[l][r];
    }
    
    int minCost(int n, vector<int>& a) {
        
        int m=a.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,INT_MAX));
        
        a.push_back(0);
        a.push_back(n);
        sort(a.begin(),a.end());
        
        return cost(a,1,m,dp);
    }
};