class Solution {
public:
    
    /*
    int find(string s1, string s2,int n1,int n2,vector<vector<int>> &dp)
    {
        if(n1==0)
            return n2;
        if(n2==0)
            return n1;
        
        if(dp[n1][n2]==-1)
        {
            if(s1[n1-1]==s2[n2-1])
                dp[n1][n2]=find(s1,s2,n1-1,n2-1,dp);
            else
                dp[n1][n2]=min({find(s1,s2,n1-1,n2-1,dp),find(s1,s2,n1,n2-1,dp),find(s1,s2,n1-1,n2,dp)})+1;
        }
        
        return dp[n1][n2];
    }
    
    int minDistance(string s1, string s2) {
        
        vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        return find(s1,s2,s1.length(),s2.length(),dp);
    }
    */
    
    int minDistance(string s1, string s2)
    {
        int n1=s1.length(),n2=s2.length();
        int i,j;
        int dp[n1+1][n2+1];
        
        for(i=0;i<=n1;i++)
        {
            for(j=0;j<=n2;j++)
            {
                if(i==0)
                    dp[i][j]=j;
                else if(j==0)
                    dp[i][j]=i;
                else if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
            }
        }
        
        return dp[n1][n2];
    }
};