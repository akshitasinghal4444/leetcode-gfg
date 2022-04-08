// { Driver Code Starts
#include <bits/stdc++.h>
#define N 10000
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    vector<int> print_next_greater_freq(int a[],int n)
    {
        // code here
        vector<int> ans(n,-1);
        unordered_map<int,int> f;
        stack<int>s;
        int i;
        
        for(i=0;i<n;i++)
            f[a[i]]++;
            
        for(i=n-1;i>=0;i--)
        {
            while(!s.empty() && f[a[i]]>=f[s.top()])
            s.pop();
            
            if(!s.empty())
            ans[i]=s.top();
            
            s.push(a[i]);
        }
        
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int arr[N];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans=ob.print_next_greater_freq(arr,n);
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout << endl;
    }
	return 1;
}
  // } Driver Code Ends