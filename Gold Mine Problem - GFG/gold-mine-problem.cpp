// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int maxGold(int n, int m, vector<vector<int>> a)
    {
        int i,j,mg;
        for(j=1;j<m;j++)
        {
            for(i=0;i<n;i++)
            {
                mg=a[i][j-1];
                if(i-1>=0)
                mg=max(mg,a[i-1][j-1]);
                if(i+1<n)
                mg=max(mg,a[i+1][j-1]);
                
                a[i][j]+=mg;
            }
        }
        mg=a[0][m-1];
        for(i=1;i<n;i++)
        mg=max(mg,a[i][m-1]);
        
        return mg;
    }

};


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends