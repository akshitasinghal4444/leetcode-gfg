//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string lexicographicallySmallest(string s, int k) {
        // code here
        int i,n=s.length();
        
        if(ceil(log2(n))==floor(log2(n)))
        k=ceil(k/2);
        else
        k*=2;
        
        if(k>=n)
        return "-1";
        
        string ans="";
        
        for(i=0;i<n;i++)
        {
            while(!ans.empty() && ans.back()>s[i] && k>0)
            {
                ans.pop_back();
                k--;
            }
            
            ans+=s[i];
        }
        
        while(k>0 && !ans.empty())
        {
            ans.pop_back();
            k--;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int k;
        cin >> S >> k;
        Solution ob;
        cout << ob.lexicographicallySmallest(S, k) << endl;
    }
    return 0;
}

// } Driver Code Ends