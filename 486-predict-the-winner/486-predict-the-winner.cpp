class Solution {
public:
    int score(vector<int>& a,int l,int r,vector<vector<int>> &dp)
    {
        if(l>r)
            return 0;
        
        if(dp[l][r]==-1)
        dp[l][r]=max(a[l]-score(a,l+1,r,dp),a[r]-score(a,l,r-1,dp));    
        
        return dp[l][r];
    }
    
    bool PredictTheWinner(vector<int>& a) {
        
        int n=a.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return score(a,0,n-1,dp)>=0;
    }
    
    /*
    int score(vector<int>& a,int l,int r)
    {
        if(l>r)
            return 0;
        return max(a[l]-score(a,l+1,r),a[r]-score(a,l,r-1));     
    }
    
    bool PredictTheWinner(vector<int>& a) {
        return score(a,0,a.size()-1)>=0;
    }
    */
    
    /*
    int score(vector<int>& a,int l,int r,bool turn)
    {
        if(l>r)
            return 0;
        
        if(turn==0)
        {
            return max(a[l]+score(a,l+1,r,!turn),a[r]+score(a,l,r-1,!turn));
        }
        else
            return min(-a[l]+score(a,l+1,r,!turn),-a[r]+score(a,l,r-1,!turn));        
    }
    
    bool PredictTheWinner(vector<int>& a) {
        return score(a,0,a.size()-1,0)>=0;
    }
    
    */
};