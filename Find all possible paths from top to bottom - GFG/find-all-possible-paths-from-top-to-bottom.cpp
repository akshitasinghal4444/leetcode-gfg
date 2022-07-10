// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> t;
    
    bool isValid(int i,int j,int n,int m,vector<vector<bool>> &vis)
    {
        return (i<n && j<m && i>=0 && j>=0 && !vis[i][j]);
    }

    void dfs(int i,int j,int n,int m,vector<vector<int>> &a,vector<vector<bool>> &vis)
    {
        
        // cout<<i<<" "<<j<<endl;
        t.push_back(a[i][j]);
        vis[i][j]=1;
        
        if(i==n-1 && j==m-1)
        {
            vis[i][j]=0;
            ans.push_back(t);
            t.pop_back();
            return;
        }
        
        if(isValid(i+1,j,n,m,vis))
        dfs(i+1,j,n,m,a,vis);
        
        if(isValid(i,j+1,n,m,vis))
        dfs(i,j+1,n,m,a,vis);
        
        vis[i][j]=0;
        t.pop_back();
    }

    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &a)
    {
        // code here
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        dfs(0,0,n,m,a,vis);
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends