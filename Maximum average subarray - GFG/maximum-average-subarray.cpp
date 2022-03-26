// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMaxAverage(int a[], int n, int k) {
        // code here
        int e=k-1;
        int i;
        int sum=0,mx=0;
        
        for(i=0;i<k;i++)
            sum+=a[i];
            
        mx=sum;
        
        while(i<n)
        {
            sum-=a[i-k];
            sum+=a[i];
            
            if(sum>mx)
            {
                e=i;
                mx=sum;
            }
            
            i++;
        }
        
        return e-k+1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxAverage(arr, n, k);
        for (int i = ans; i < ans + k; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends