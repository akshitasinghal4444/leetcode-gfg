// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int biGraph(int a[], int n, int e)
    {
        
        if(n==1 || (n==2 && e==1))
        return 1;
        
        vector<int> f(n);
        
        for(int i=0;i<e;i++)
        {
            f[a[2*i]]++;
            f[a[2*i+1]]++;
        }
        
        for(int x:f)
        {
            if(x<2)
            return 0;
        }
        return 1;
    }
  
  /*
    int biGraph(int arr[], int n, int e) {
       // code here
       if(n==1)return 1;
       if(n==2&&e==1)return 1;
       vector<int>g[n];
       for(int i=0;i<2*e;i+=2){
           int u=arr[i];
           int v=arr[i+1];
           g[u].push_back(v);
           g[v].push_back(u);
       }
       for(auto i:g){
        if(i.size()<2){
            return 0;
        }   
       }
       return 1;
   }
   */
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        cin>>n>>e;
        
        int arr[2*e];
        for(int i=0; i<2*e; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.biGraph(arr,n,e) << endl;
    }
    return 0;
}  // } Driver Code Ends