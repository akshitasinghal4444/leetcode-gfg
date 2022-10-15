class Solution {
public:
    
    int minDistance(string s1, string s2)
    {
        int n1=s1.length(),n2=s2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        int i,j;
        
        for(i=n1;i>=0;i--)
        {
            for(j=n2;j>=0;j--)
            {
                if(i==n1)
                    dp[i][j]=n2-j;
                else if(j==n2)
                    dp[i][j]=n1-i;
                else if(s1[i]==s2[j])
                    dp[i][j]=dp[i+1][j+1];
                else
                    dp[i][j]=1+min({dp[i+1][j+1],dp[i+1][j],dp[i][j+1]});
            }
        }
        
        return dp[0][0];
    }
    
    /*
    int minDistance(string s1, string s2,int i,int j,int n1,int n2,vector<vector<int>> &dp)
    {
        if(i==n1)
            return n2-j;
        
        if(j==n2)
            return n1-i;
        
        if(dp[i][j]==-1)
        {
            if(s1[i]==s2[j])
                dp[i][j]=minDistance(s1,s2,i+1,j+1,n1,n2,dp);
            else
            {
                dp[i][j]= 1+min({minDistance(s1,s2,i+1,j+1,n1,n2,dp),minDistance(s1,s2,i+1,j,n1,n2,dp),minDistance(s1,s2,i,j+1,n1,n2,dp)});
            }
        }
        
        return dp[i][j];
    }
    
    int minDistance(string s1, string s2) {
        
        int n1=s1.length(),n2=s2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        
        return minDistance(s1,s2,0,0,n1,n2,dp);
    }
    */
};