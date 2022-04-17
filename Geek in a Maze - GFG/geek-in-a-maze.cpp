// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
 
	public:
	int numberOfCells(int n, int m, int r, int c, int u, int d, vector<vector<char>> &a)
	{
		// Your code goes here
		int ans=0;
		queue<vector<int>> q;
		
		if(a[r][c]=='.')
		{
		    q.push({r,c,u,d});
    		a[r][c]='#';
	    	ans++;
		}
		
		while(!q.empty())
		{
		    r=q.front()[0];
		    c=q.front()[1];
		    u=q.front()[2];
		    d=q.front()[3];
		    q.pop();
		    
		    if(c-1>=0 && a[r][c-1]=='.')
		    {
		        ans++;
		        q.push({r,c-1,u,d});
		        a[r][c-1]='#';
		    }
		    
		    if(c+1<m && a[r][c+1]=='.')
		    {
		        ans++;
		        q.push({r,c+1,u,d});
		        a[r][c+1]='#';
		    }
		    
		    if(u>0 && r-1>=0 && a[r-1][c]=='.')
		    {
		        ans++;
		        q.push({r-1,c,u-1,d});
		        a[r-1][c]='#';
		    }
		    
		    if(d>0 && r+1<n && a[r+1][c]=='.')
		    {
		        ans++;
		        q.push({r+1,c,u,d-1});
		        a[r+1][c]='#';
		    }
		    
		}
		
		return ans;
	}

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;

    while (t--)
    {
    	int n, m, r, c, u, d;
        cin >> n >> m >> r >> c >> u >> d;
        
        vector<vector<char>> mat(n, vector<char>(m, '.'));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < m; j++)
        	{
        		cin >> mat[i][j];
        	}
        }

      

        Solution obj;
        cout << obj.numberOfCells(n, m, r, c, u, d, mat) << "\n";
    
    }

    return 0;
}


  // } Driver Code Ends