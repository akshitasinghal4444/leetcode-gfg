class Solution {
public:
    int minimumTotal(vector<vector<int>>& a)
    {
        int i,j,n=a.size();
        
        vector<int> dp1;
        dp1=a[0];
        
        for(i=1;i<n;i++)
        {
            vector<int> dp2;
            
            dp2.push_back(a[i][0]+dp1[0]);
            
            for(j=1;j<i;j++)
                dp2.push_back(a[i][j]+min(dp1[j-1],dp1[j]));
            
            dp2.push_back(a[i][j]+dp1[j-1]);
            
            dp1=dp2;
            
//             for(auto x:dp1)
//                 cout<<x<<" ";
            
//             cout<<endl;
        }
        
        return *min_element(dp1.begin(),dp1.end());
    }
    
    /*
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
    */
};