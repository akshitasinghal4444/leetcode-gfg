// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int a[], int n)
    {
        // Your code here
        vector<int> l(n,-1),r(n,n),ans(n,INT_MIN);
        stack<int> s;
        int i;
        
        for(i=0;i<n;i++)
        {
            while(!s.empty() && a[s.top()]>a[i])
            {
                r[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        
        while(!s.empty())
        s.pop();
        
        for(i=n-1;i>=0;i--)
        {
            while(!s.empty() && a[s.top()]>a[i])
            {
                l[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        
        for(i=0;i<n;i++)
        ans[r[i]-l[i]-2]=max(ans[r[i]-l[i]-2],a[i]);
        
        int mx=ans[n-1];
        for(i=n-2;i>=0;i--)
        {
            ans[i]=mx=max(ans[i],mx);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends