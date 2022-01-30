// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    
    bool isValid(vector<vector<int>> &a, int i,int j,int n)
    {
        return (i>=0 && j>=0 && i<n && j<n && a[i][j]);
    }
    
    void dfs(vector<vector<int>> &a, int n,int i,int j,string s)
    {
        if(i==n-1 && j==n-1)
        {
            ans.push_back(s);
            return ;
        }
        
        a[i][j]=0;
        int x[]={-1,0,1,0},y[]={0,1,0,-1};
        char dir[]={'U','R','D','L'};
        int k;
        
        for(k=0;k<4;k++)
        {
            if(isValid(a,i+x[k],j+y[k],n))
            {
                // a[i+x[k]][j+y[k]]=0;
                s+=dir[k];
                dfs(a,n,i+x[k],j+y[k],s);
                s.pop_back();
                a[i+x[k]][j+y[k]]=1;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &a, int n) {
        // Your code goes here
        
        ans={};
        if(a[0][0]!=0 && a[n-1][n-1]!=0)
        dfs(a,n,0,0,"");
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends