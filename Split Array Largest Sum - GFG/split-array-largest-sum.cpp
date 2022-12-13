//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    bool possible(int *a ,int n, int k,int mid)
    {
        int i;
        long s=0;
        k--;
        
        for(i=0;i<n;i++)
        {
            s+=a[i];
            
            if(s>mid)
            {
                s=a[i];
                k--;
            }
            
            if(k<0)
            return 0;
        }
        
        return 1;
    }
  
    int splitArray(int a[] ,int n, int k) {
        // code here
        long i,l,h,ans;
        l=h=a[0];
        
        for(i=0;i<n;i++)
        {
            h+=a[i];
            l=max(l,(long)a[i]);
        }
        ans=h;
        
        while(l<=h)
        {
            int mid=(l+h)/2;
            
            // cout<<l<<" "<<mid<<" "<<h<<" "<<ans<<":";
            
            if(possible(a,n,k,mid))
            {
                ans=mid;
                h=mid-1;
            }
            else
            l=mid+1;
            
            // cout<<l<<" "<<mid<<" "<<h<<" "<<ans<<endl;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends