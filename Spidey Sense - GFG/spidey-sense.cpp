// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

    public:
    vector<vector<int> > findDistance(vector<vector<char> >& a, int m, int n) 
    { 
        // Your code goes here
        vector<vector<int>> dp(m,vector<int>(n));
        int i,j;
        queue<pair<int,int>> q;
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]=='W')
                dp[i][j]=-1;
                else if(a[i][j]=='B')
                {
                    dp[i][j]=0;
                    q.push({i,j});
                }
                else 
                dp[i][j]=INT_MAX;
            }
        }
        
        while(!q.empty())
        {
            int s=q.size();
            
            while(s--)
            {
                i=q.front().first;
                j=q.front().second;
                q.pop();
                
                if(i-1>=0 && dp[i-1][j]==INT_MAX)
                {
                    q.push({i-1,j});
                    dp[i-1][j]=dp[i][j]+1;
                }
                
                if(j+1<n && dp[i][j+1]==INT_MAX)
                {
                    q.push({i,j+1});
                    dp[i][j+1]=dp[i][j]+1;
                }
                
                if(j-1>=0 && dp[i][j-1]==INT_MAX)
                {
                    q.push({i,j-1});
                    dp[i][j-1]=dp[i][j]+1;
                }
                
                if(i+1<m && dp[i+1][j]==INT_MAX)
                {
                    q.push({i+1,j});
                    dp[i+1][j]=dp[i][j]+1;
                }
            }
        }
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(dp[i][j]==INT_MAX)
                dp[i][j]=-1;
            }
        }
        
        return dp;
    } 
};

// { Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}  // } Driver Code Ends