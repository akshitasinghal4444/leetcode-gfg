//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void dfs(vector<vector<char>> &a,int m,int n,int i,int j)
    {
        if(i<0 || j<0 || i>=m || j>=n || a[i][j]!='O')
        return;
        
        a[i][j]='-';
        dfs(a,m,n,i-1,j);
        dfs(a,m,n,i+1,j);
        dfs(a,m,n,i,j-1);
        dfs(a,m,n,i,j+1);
    }

    vector<vector<char>> fill(int m, int n, vector<vector<char>> a)
    {
        // code here
        int i,j;

        for(i=0,j=0;i<m;i++)
        {
            if(a[i][j]=='O')
            dfs(a,m,n,i,j);
        }
        
        for(i=0,j=n-1;i<m;i++)
        {
            if(a[i][j]=='O')
            dfs(a,m,n,i,j);
        }
        
        for(i=0,j=0;j<n;j++)
        {
            if(a[i][j]=='O')
            dfs(a,m,n,i,j);
        }
        
        for(i=m-1,j=0;j<n;j++)
        {
            if(a[i][j]=='O')
            dfs(a,m,n,i,j);
        }
        
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]=='-')
                a[i][j]='O';
                else
                a[i][j]='X';
            }
        }
        
        return a;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends