class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        int i,j,dis;
        vector<vector<int>> dp(m,vector<int> (n,INT_MAX));
        queue<pair<int,int>> q;
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]==0)
                {
                    dp[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        dis=0;
        while(!q.empty())
        {
            int s=q.size();
            dis++;
            
            while(s--)
            {
                i=q.front().first;
                j=q.front().second;
                q.pop();
                
                if(i-1>=0 && dp[i-1][j]==INT_MAX)
                {
                    dp[i-1][j]=dis;
                    q.push({i-1,j});
                }
                
                if(i+1<m && dp[i+1][j]==INT_MAX)
                {
                    dp[i+1][j]=dis;
                    q.push({i+1,j});
                }
                
                if(j-1>=0 && dp[i][j-1]==INT_MAX)
                {
                    dp[i][j-1]=dis;
                    q.push({i,j-1});
                }
                
                if(j+1<n && dp[i][j+1]==INT_MAX)
                {
                    dp[i][j+1]=dis;
                    q.push({i,j+1});
                }
            }
        }
        
        return dp;
    }
};