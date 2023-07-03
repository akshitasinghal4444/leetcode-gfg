//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int a[], int n) {
        // code here
        int i,j,lmin[n],rmax[n],ans=-1;
        lmin[0]=a[0];
        rmax[n-1]=a[n-1];
        
        for(i=1;i<n;i++)
        lmin[i]=min(a[i],lmin[i-1]);
        
        for(j=n-2;j>=0;j--)
        rmax[j]=max(rmax[j+1],a[j]);
        
        i=0,j=0;
        
        while(i<n && j<n)
        {
            if(lmin[i]<=rmax[j])
            {
                ans=max(ans,j-i);
                j++;
            }
            else
                i++;
        }
        
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends