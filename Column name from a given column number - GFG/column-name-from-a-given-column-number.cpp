// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string s="";
        while(n)
        {
            int x=n%26;
            x=(x==0?26:x);
            s+=(x-1)+'A';
            n=n-x;
            n=n/26;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends