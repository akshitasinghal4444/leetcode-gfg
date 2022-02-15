// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> a)
    {
        int i,j;
        
        for(i=1;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                int x=a[i-1][j];
                
                if(j-1>=0)
                x=max(a[i-1][j-1],x);
                
                if(j+1<n)
                x=max(a[i-1][j+1],x);
                
                a[i][j]+=x;
                
            }
        }
        
        int mx=a[n-1][0];
        for(j=1;j<n;j++)
        mx=max(mx,a[n-1][j]);
        
        return mx;
    }

/*
    int maximumPath(int n, vector<vector<int>> a)
    {
        // code here
        int i,j;
        int m;
        for(i=1;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                m=a[i-1][j];
                
                if(j-1>=0)
                m=max(m,a[i-1][j-1]);
                if(j+1<n)
                m=max(m,a[i-1][j+1]);
                a[i][j]+=m;
            }
        }
        m=a[n-1][0];
        for(j=1;j<n;j++)
        m=max(m,a[n-1][j]);
        
        return m;
    }
    */
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends