// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
	int FindWays(int n, int m, vector<vector<int>>b){
	    // Code here
	    vector<vector<int>> a(n,vector<int>(m,1));
	    int i,j;
	    int mod=1e9+7;
	    
	    for(auto v:b)
	        a[v[0]-1][v[1]-1]=0;
	    
	    for(i=n-1;i>=0;i--)
	    {
	        for(j=m-1;j>=0;j--)
	        {
	            if((i==n-1 && j==m-1)||a[i][j]==0)
	            continue;
	            else if(i==n-1)
	                a[i][j]=a[i][j+1];
	            else if(j==m-1)
	                a[i][j]=a[i+1][j];
	            else
	            a[i][j]=(a[i+1][j]+a[i][j+1])%mod;
	        }
	    }
	    return a[0][0];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends