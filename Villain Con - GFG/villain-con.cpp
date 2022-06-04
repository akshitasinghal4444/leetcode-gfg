// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minColour(int n, int m, vector<int> mat[]) {
        // code here
        vector<int> a[n+1],in(n+1,0);
        queue<int> q;
        int i,ans=0;
        
        for(i=0;i<m;i++)
        {
            a[mat[i][0]].push_back(mat[i][1]);
            in[mat[i][1]]++;
        }
        
        for(i=1;i<n;i++)
        {
            if(in[i]==0)
            q.push(i);
        }
        
        
        while(!q.empty())
        {
            ans++;
            int s=q.size();
            while(s--)
            {
                i=q.front();
                q.pop();
                
                for(int j:a[i])
                {
                    in[j]--;
                    if(in[j]==0)
                    q.push(j);
                }
            }
        }
        
        return ans;
    }
};




// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M, x, y;
        cin>>N>>M;
        vector<int> mat[M];
        for(int i = 0;i < M;i++){
            cin>>x>>y;
            mat[i].push_back(x);
            mat[i].push_back(y);
        }
        
        Solution ob;
        cout<<ob.minColour(N, M, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends