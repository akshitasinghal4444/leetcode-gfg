// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> a){
        // code here
        int i,j;
        
        for(i=0;i<9;i++)
        {
            int f[10]={0};
            for(j=0;j<9;j++)
            {
                f[a[i][j]]++;
                
                if(a[i][j] && f[a[i][j]]>1)
                return 0;
            }
        }
        
        for(j=0;j<9;j++)
        {
            int f[10]={0};
            for(i=0;i<9;i++)
            {
                f[a[i][j]]++;
                
                if(a[i][j] && f[a[i][j]]>1)
                return 0;
            }
        }
        
        i=0;
        j=0;
        int b[9][10]={0};
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(i>=0 && i<=2 && j>=0 && j<=2)
                {
                    b[0][a[i][j]]++;
                    if(a[i][j] && b[0][a[i][j]]>1)
                    return 0;
                }
                else if(i>=0 && i<=2 && j>=3 && j<=5)
                {
                    b[1][a[i][j]]++;
                    if(a[i][j] && b[1][a[i][j]]>1)
                    return 0;
                }
                else if(i>=0 && i<=2 && j>=5 && j<=8)
                {
                    b[2][a[i][j]]++;
                    if(a[i][j] && b[2][a[i][j]]>1)
                    return 0;
                }
                else if(i>=3 && i<=5 && j>=0 && j<=2)
                {
                    b[3][a[i][j]]++;
                    if(a[i][j] && b[3][a[i][j]]>1)
                    return 0;
                }
                else if(i>=3 && i<=5 && j>=3 && j<=5)
                {
                    b[4][a[i][j]]++;
                    if(a[i][j] && b[4][a[i][j]]>1)
                    return 0;
                }
                else if(i>=3 && i<=5 && j>=5 && j<=8)
                {
                    b[5][a[i][j]]++;
                    if(a[i][j] && b[5][a[i][j]]>1)
                    return 0;
                }
                else if(i>=6 && i<=8 && j>=0 && j<=2)
                {
                    b[6][a[i][j]]++;
                    if(a[i][j] && b[6][a[i][j]]>1)
                    return 0;
                }
                else if(i>=6 && i<=8 && j>=3 && j<=5)
                {
                    b[7][a[i][j]]++;
                    if(a[i][j] && b[7][a[i][j]]>1)
                    return 0;
                }
                else if(i>=6 && i<=8 && j>=5 && j<=8)
                {
                    b[8][a[i][j]]++;
                    if(a[i][j] && b[8][a[i][j]]>1)
                    return 0;
                }
            }
        }
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends