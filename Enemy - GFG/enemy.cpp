//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int m,int n,int k,vector<vector<int>> &a)
        {
            //  code here
            vector<int> r,c;
            r.push_back(0);
            r.push_back(m+1);
            c.push_back(0);
            c.push_back(n+1);
            
            for(auto v:a)
            {
                r.push_back(v[0]);
                c.push_back(v[1]);
            }
            
            sort(r.begin(),r.end());
            sort(c.begin(),c.end());
            
            int i,l=0,b=0;
        
            
            for(i=1;i<k+2;i++)
            {
                l=max(l,r[i]-r[i-1]-1);
                b=max(b,c[i]-c[i-1]-1);
                // cout<<r[i]<<" "<<c[i]<<endl;
            }
            
            return l*b;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends