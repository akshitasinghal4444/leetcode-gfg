// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findHeight(int n, int a[]){
        // code here
        vector<int> v(n);
        int i,mx=0;
        
        for(i=0;i<n;i++)
        {
            if(a[i]==-1)
            v[i]=1;
            else
            v[i]=v[a[i]]+1;
            
            // mx=max(mx,v[i]);
        }
        
        return v[n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.findHeight(N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends