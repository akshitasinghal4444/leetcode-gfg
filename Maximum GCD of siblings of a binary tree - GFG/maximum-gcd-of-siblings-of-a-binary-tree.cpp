// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int maxBinTreeGCD(vector<vector<int>> a, int n)
  {
      unordered_map<int,vector<int>> m;
      int ans=0;
      
      for(auto v:a)
      m[v[0]].push_back(v[1]);
      
      for(auto it:m)
      {
         if(it.second.size()>=2)
         ans=max(ans,__gcd(it.second[0],it.second[1]));
      }
      
      return ans;
  }
  
  /*
    int maxBinTreeGCD(vector<vector<int>> a, int n) {
        // code here
        int i,ans=0;
        n=a.size();
        sort(a.begin(),a.end());
        
        for(i=1;i<n;i++)
        {
            if(a[i][0]==a[i-1][0])
            ans=max(ans,__gcd(a[i-1][1],a[i][1]));
        }
        
        return ans;
    }
    */
    
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,u,v;
        cin>>N;
        
        vector<vector<int>> arr;
        
        for(int i=0; i<N-1; i++)
        {
            cin>>u>>v;
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            arr.push_back(edge);
        }

        Solution ob;
        cout << ob.maxBinTreeGCD(arr,N) << endl;
    }
    return 0;
}  // } Driver Code Ends