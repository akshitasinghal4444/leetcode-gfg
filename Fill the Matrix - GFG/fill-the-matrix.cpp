//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int n, int m, int x, int y){    
        // code here
        int ans=0;
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        
        vis[x-1][y-1]=1;
        q.push({x-1,y-1});
        
        while(!q.empty())
        {
            ans++;
            int s=q.size();
            
            while(s--)
            {
                x=q.front().first;
                y=q.front().second;
                q.pop();
                
                if(x-1>=0 && !vis[x-1][y])
                {
                    vis[x-1][y]=1;
                    q.push({x-1,y});
                }
                
                if(x+1<n && !vis[x+1][y])
                {
                    vis[x+1][y]=1;
                    q.push({x+1,y});
                }
                
                if(y-1>=0 && !vis[x][y-1])
                {
                    vis[x][y-1]=1;
                    q.push({x,y-1});
                }
                
                if(y+1<m && !vis[x][y+1])
                {
                    vis[x][y+1]=1;
                    q.push({x,y+1});
                }
            }
        }
        
        return ans-1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends