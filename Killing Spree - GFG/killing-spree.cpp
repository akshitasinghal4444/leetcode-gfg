// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    long long int killinSpree(long long int n)
   {
       // Code Here
       long long int l=1,r=1e6,ans=-1;
       while(l<=r){
           long long int mid=(l+r)/2;
           if(mid*(mid+1)*(2*mid+1)/6<=n){
               ans=mid;
               l=mid+1;
           }
           else{
               r=mid-1;
           }
       }
       return ans;
   }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n; cin>>n;
        Solution obj;
        long long int ans = obj.killinSpree(n);
        cout<<ans<<"\n";
    }
    return 0;
}
  // } Driver Code Ends