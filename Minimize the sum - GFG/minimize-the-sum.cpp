//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int n, vector<int> a) {
        // code here
        priority_queue<int,vector<int>,greater<int>> q(a.begin(),a.end());
        int ans=0;
        
        while(q.size()>1)
        {
            int a=q.top();
            q.pop();
            
            int b=q.top();
            q.pop();
            
            ans+=a+b;
            q.push(a+b);
        }
        
        // ans+=q.top();
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends