//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&a){
	    // Code here
	    int n=a.size();
	    int i,j,k;
	    
	    for(k=0;k<n;k++)
	    {
	        for(i=0;i<n;i++)
	        {
	            for(j=0;j<n;j++)
	            {
	                if(a[i][k]!=-1 && a[k][j]!=-1 && (a[i][j]==-1 || a[i][j]>a[i][k]+a[k][j]))
	                a[i][j]=a[i][k]+a[k][j];
	            }
	        }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends