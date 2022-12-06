//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>a)
	{
	    // Code here
	    int m=a.size(),n=a[0].size();
	    int i,j,si,sj;
	    vector<vector<int>> ans(m,vector<int>(n,-1));
	    queue<vector<int>> q;
	    
	    for(i=0;i<m;i++)
	    {
	        for(j=0;j<n;j++)
	        {
	            if(a[i][j]==1)
	            {
	                q.push({i,j,i,j});
	                ans[i][j]=0;
	            }
	        }
	    }
	    
	    while(!q.empty())
	    {
	        i=q.front()[0];
	        j=q.front()[1];
	        si=q.front()[2];
	        sj=q.front()[3];
	        q.pop();
	        
	        if(i-1>=0 && a[i-1][j]==0 && ans[i-1][j]==-1)
	        {
	            q.push({i-1,j,si,sj});
	            ans[i-1][j]=abs(si-(i-1))+abs(sj-(j));
	        }
	        
	        if(i+1<m && a[i+1][j]==0 && ans[i+1][j]==-1)
	        {
	            q.push({i+1,j,si,sj});
	            ans[i+1][j]=abs(si-(i+1))+abs(sj-(j));
	        }
	        
	        if(j-1>=0 && a[i][j-1]==0 && ans[i][j-1]==-1)
	        {
	            q.push({i,j-1,si,sj});
	            ans[i][j-1]=abs(si-(i))+abs(sj-(j-1));
	        }
	        
	        if(j+1<n && a[i][j+1]==0 && ans[i][j+1]==-1)
	        {
	            q.push({i,j+1,si,sj});
	            ans[i][j+1]=abs(si-(i))+abs(sj-(j+1));
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends