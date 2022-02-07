// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool is_possible(int *a,int mid,int n,int m)
    {
        int s=1,p=0;
        
        int i;
        for(i=0;i<n;i++)
        {
            if(a[i]>mid)
            return 0;
            
            if(p+a[i]<=mid)
            {
                p+=a[i];
            }
            else
            {
                p=a[i];
                s++;
            }
        }
        if(s<=m)
        return 1;
        
        return 0;
    }
    
    int findPages(int a[], int n, int m) 
    {
        //code here
        int i;
        int l=INT_MIN,h=0,ans=-1;
        
        for(i=0;i<n;i++)
        {
            l=max(l,a[i]);
            h+=a[i];
        }
        
        while(l<=h)
        {
            int mid=(l+h)/2;
            
            if(is_possible(a,mid,n,m))
            {
                ans=mid;
                // cout<<ans<<endl;
                h=mid-1;
            }
            else
            l=mid+1;
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends