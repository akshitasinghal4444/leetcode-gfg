//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

class Solution {
  public:
  
    int sum(int n)
    {
        int s=0;
        
        while(n>0)
        {
            s+=(n%10);
            n/=10;
        }
        
        return s;
    }
  
    string BalancedString(int n) {
        // code here
        string ans ="";
        int i,mid;
        
        if(n%2==0)
            mid=(n%26)/2;
        else
        {
            if(sum(n)%2==0)
            mid=(n%26+1)/2;
            else
            mid=(n%26-1)/2;
        }
        
        while(n>26)
        {
            ans+="abcdefghijklmnopqrstuvwxyz";
            n-=26;
        }
        
        
        
        for(i=0;i<mid;i++)
        ans+=('a'+i);
        
        // cout<<i<<" "<<n<<endl;
        
        string t="";
        for(char c='z';i<n;i++,c--)
        t+=c;
        
        
        reverse(t.begin(),t.end());
        ans+=t;
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends