//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:

    bool isvalid(int i,int j,int m,int n,vector<vector<int>>& a)
    {
        return (i<m && i>=0 && j>=0 && j<n && a[i][j]==0);
    }

    int Count(vector<vector<int> >& a) {
        // Code here
        int m=a.size(),n=a[0].size();
        int i,j,k,c=0;
        int di[]={-1,-1,-1,0,0,1,1,1},dj[]={-1,0,1,-1,1,-1,0,1};
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]==0)
                continue;
                
                int x=0;
                for(k=0;k<8;k++)
                {
                    if(isvalid(i+di[k],j+dj[k],m,n,a))
                    x++;
                }
                
                if(x!=0 && x%2==0)
                    c++;
            }
        }
        
        return c;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends