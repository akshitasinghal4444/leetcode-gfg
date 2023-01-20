//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int n, vector<int> a)
  {
      // code here
      vector<int> v(n,0);
      int i,ans=n-1;
      
      for(i=0;i<n;i++)
      {
          if(a[i]==-1)
          continue;
          
          v[a[i]]+=i;
          
          if(v[a[i]]>v[ans])
          ans=a[i];
          else if(v[a[i]]==v[ans])
          ans=max(a[i],ans);
      }
      
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends