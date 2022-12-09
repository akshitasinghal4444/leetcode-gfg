//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
bool valid(int i,int j,int m,int n)
{
    return i>=0 && j>=0 && i<m && j<n;
}

long long numOfWays(int m, int n)
{
    // write code here
    long long ans=0,t=m*n;
    int mod=1e9+7;
    int i,j,k;
    int dx[]={-2,-2,-1,-1,1,1,2,2};
    int dy[]={-1,1,-2,2,-2,2,-1,1};
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            int c=1;
            
            for(k=0;k<8;k++)
            {
                if(valid(i+dx[k],j+dy[k],m,n))
                c++;
            }
            
            ans+=(t-c);
            ans%=mod;
        }
    }
    
    return ans;
}