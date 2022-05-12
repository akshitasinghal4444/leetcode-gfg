// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& g) 
    {
        //code here
        int n=g.size();
        int i,j;
        bool f=0;
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(g[i][j]==1)
                {
                    f=1;
                    break;
                }
            }
            if(f)
            break;
        }
        
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        
        q.push({i,j});
        vis[i][j]=1;
        
        while(!q.empty())
        {
            i=q.front().first;
            j=q.front().second;
            q.pop();
            
            if(i+1<n && !vis[i+1][j] && g[i+1][j]!=0)
            {
                if(g[i+1][j]==2)
                return 1;
                vis[i+1][j]=1;
                q.push({i+1,j});
            }
            
            if(i-1>=0 && !vis[i-1][j] && g[i-1][j]!=0)
            {
                if(g[i-1][j]==2)
                return 1;
                vis[i-1][j]=1;
                q.push({i-1,j});
            }
            
            if(j+1<n && !vis[i][j+1] && g[i][j+1]!=0)
            {
                if(g[i][j+1]==2)
                return 1;
                vis[i][j+1]=1;
                q.push({i,j+1});
            }
            
            if(j-1>=0 && !vis[i][j-1] && g[i][j-1]!=0)
            {
                if(g[i][j-1]==2)
                return 1;
                vis[i][j-1]=1;
                q.push({i,j-1});
            }
        }
        
        return 0;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends