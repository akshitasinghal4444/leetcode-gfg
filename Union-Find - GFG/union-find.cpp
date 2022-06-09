// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    int find(int a, int *parent) {
        if(parent[a] == a) {
            return a;
        }
        return parent[a] = find(parent[a], parent);
    }
    
    void union_( int x, int y, int parent[], int ranked[]) 
    {
        int s1 = find(x,parent);
        int s2 = find(y,parent);
    
        if (s1 != s2) {
            if (ranked[s1] < ranked[s2]) {
                parent[s1] = s2;
                ranked[s2] += ranked[s1];
            }
            else {
                parent[s2] = s1;
                ranked[s1] += ranked[s2];
            }
        }
    }
    
    bool isConnected(int a,int b, int parent[], int rank1[])
    {
        if(find(a,parent) == find(b,parent)) return true;
        else return false;
    }
};

// { Driver Code Starts.

int main() {
    //taking number of testcases
    int t;
    cin>>t;
    while(t--) {
        
        //taking number of elements
        int n;
        cin>>n;
        
        
        int par[n+1];
        int rank1[n+1];

        //initializing the parent and
        //the rank array
        for(int i=1; i<=n; i++) {
            par[i] = i;
            rank1[i] = 1;
    }
    
    //taking number of queries
    Solution obj;
    int q;
    cin>>q;
    while(q--) {    
        int a,b;
        char c;
        cin>>c>>a>>b;
        
        //if query type is 'U'
        //then calling union_ method
        if(c=='U')
        {
            obj.union_(a,b, par, rank1);
        }
        else//else calling isConnected() method
        cout<<obj.isConnected(a,b, par, rank1)<<endl;
    }
    }
    return 0;
}
  // } Driver Code Ends