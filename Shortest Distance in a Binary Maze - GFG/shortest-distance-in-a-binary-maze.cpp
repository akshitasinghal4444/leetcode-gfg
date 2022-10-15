//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &g, pair<int, int> s,
                     pair<int, int> d) {
        // code here
        if(g[s.first][s.second]==0 || g[d.first][d.second]==0)
        return -1;
        
        if(s.first==d.first && s.second==d.second)
        return 0;
        
        int m=g.size(),n=g[0].size();
        
        queue<pair<int,int>> q;
        q.push(s);
        g[s.first][s.second]=0;
        int ans=0;
        
        while(!q.empty())
        {
            int size=q.size();
            ans++;
            
            while(size--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                
                if(i-1>=0 && g[i-1][j])
                {
                    if(i-1==d.first && j==d.second)
                    return ans;
                    
                    q.push({i-1,j});
                    g[i-1][j]=0;
                }
                
                if(i+1<m && g[i+1][j])
                {
                    if(i+1==d.first && j==d.second)
                    return ans;
                    
                    q.push({i+1,j});
                    g[i+1][j]=0;
                }
                
                if(j-1>=0 && g[i][j-1])
                {
                    if(i==d.first && j-1==d.second)
                    return ans;
                    
                    q.push({i,j-1});
                    g[i][j-1]=0;
                }
                
                if(j+1<n && g[i][j+1])
                {
                    if(i==d.first && j+1==d.second)
                    return ans;
                    
                    q.push({i,j+1});
                    g[i][j+1]=0;
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends