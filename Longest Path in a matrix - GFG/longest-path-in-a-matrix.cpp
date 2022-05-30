// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void dfs(int x  , int y , int n , int m , vector<vector<int>>& matrix , vector<vector<int>>& vis , vector<vector<int>>& dp){
        vis[x][y] = 1;
        dp[x][y] = 1;
        int dx[] = {-1 , 1 , 0 , 0};
        int dy[] = {0 , 0 , -1 , 1};
        int maxi = 0;
        for(int i = 0 ; i < 4 ; i++){
            if(x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < m ){
                if(matrix[x + dx[i]][y + dy[i]] > matrix[x][y]){
                    if(vis[x + dx[i]][y + dy[i]] == 0){
                        dfs(x + dx[i] , y + dy[i] , n , m , matrix , vis , dp);
                    }
                    maxi = max(maxi , dp[x + dx[i]][y + dy[i]]);
                }
            }
        }
        dp[x][y] += maxi;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // Code here
        int n = matrix.size() , m = matrix[0].size();
        vector<vector<int>>vis(n , vector<int>(m , 0));
        vector<vector<int>>dp(n , vector<int>(m , 0));
        int maxi = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ;  j < m ; j++){
                if(vis[i][j] == 0)
                dfs(i , j , n , m , matrix , vis , dp);
                maxi = max(maxi , dp[i][j]);
            }
        }
        return maxi ;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends