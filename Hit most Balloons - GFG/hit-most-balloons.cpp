// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    double slope(double x1,double y1,double x2,double y2)
    {
        double ans;
        ans=(y2-y1)/(x2-x1);
        return ans;
    }
  
    int mostBalloons(int n, pair<int, int> a[]) {
        // Code here
        int mx=0;
        int i,j;
        for(i=0;i<n;i++)
        {
            unordered_map<double,int> m;
            int c=0;
            
            for(j=i+1;j<n;j++)
            {
                if(a[i]==a[j])
                {
                    c++;
                    continue;
                }
                
                double x=slope(a[i].first,a[i].second,a[j].first,a[j].second);
                m[x]++;
                
            }
            for(auto &e : m){
                mx = max(mx, e.second + c);
            }
        }
        
        return mx+1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        pair<int, int> arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> arr[i].second;
        }
        Solution ob;
        cout << ob.mostBalloons(N, arr) << endl;
    }
}  // } Driver Code Ends