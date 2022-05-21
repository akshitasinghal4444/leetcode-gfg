// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> farNumber(int n,vector<int> a){
        //code here
        
        int i;
        vector<int> mn(n),ans(n,-1);
        mn[n-1]=n-1;
        
        for(i=n-2;i>=0;i--)
        {
            if(a[i]<a[mn[i+1]])
            mn[i]=i;
            else
            mn[i]=mn[i+1];
        }
        
        
        for(i=0;i<n-1;i++)
        {
            int l,h;
            l=i+1;
            h=n-1;
            
            while(l<=h)
            {
                int mid=(l+h)/2;
                if(a[mn[mid]]<a[i])
                {
                    ans[i]=mn[mid];
                    l=mid+1;
                }
                else
                h=mid-1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends