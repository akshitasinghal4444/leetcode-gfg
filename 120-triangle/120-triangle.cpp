class Solution {
public:
    int minimumTotal(vector<vector<int>>& a,int r,int c,int n,vector<vector<int>> &dp)
    {
        if(r==n)
            return 0;
        
        if(dp[r][c]==INT_MAX)
        {
            dp[r][c]=a[r][c]+min(minimumTotal(a,r+1,c,n,dp),minimumTotal(a,r+1,c+1,n,dp));
        }
        
        return dp[r][c]; 
    }
    
    int minimumTotal(vector<vector<int>>& a) {
        int n=a.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        
        return minimumTotal(a,0,0,n,dp);
    }
};