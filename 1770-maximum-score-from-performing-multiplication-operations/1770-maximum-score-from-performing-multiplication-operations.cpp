class Solution {
public:
    int score(vector<int>& a, vector<int>& mul,int l,int r,int n,int in,vector<vector<int>> &dp)
    {
        if(in==n || l>r)
            return 0;
        
        if(dp[l][in]==INT_MIN)
        {
            int ls=(mul[in]*a[l])+score(a,mul,l+1,r,n,in+1,dp);
            int rs=(mul[in]*a[r])+score(a,mul,l,r-1,n,in+1,dp);
        
            dp[l][in]=max(ls,rs);
        }
        
        return dp[l][in];
    }
    
    int maximumScore(vector<int>& a, vector<int>& mul) {
        int na=a.size(),nm=mul.size();
        vector<vector<int>> dp(nm,vector<int>(nm,INT_MIN));
        
        return score(a,mul,0,na-1,nm,0,dp);
    }
};