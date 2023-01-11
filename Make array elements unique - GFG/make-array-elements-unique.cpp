//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> a, int n) {
        // Code here
        sort(a.begin(),a.end());
        long long ans=0;
        
        for(int i=1;i<n;i++)
        {
            if(a[i]<=a[i-1])
            {
                ans+=a[i-1]-a[i]+1;
                a[i]=a[i-1]+1;
            }
            // cout<<a[i]<<" ";
        }
        
        return ans;
    }
    
    /*
    
    4 5 4 1 3 7 6 3 3
    1 3 3 3 4 4 5 6 7
    1 3 4 5 6 7 8 9 10
    */
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends