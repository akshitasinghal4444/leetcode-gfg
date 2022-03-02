// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long countStrings(string s)
    {
        // code here
        int n=s.length();
        int i,f[26]={0};
        long long c=0;
        int x=0;
        
        for(i=n-1;i>=0;i--)
        {
            int in=s[i]-'a';
            for(int j=0;j<26;j++)
            {
                if(j==in)
                continue;
                else
                c+=f[j];
            }
            
            f[in]++;
            
            if(f[in]>1)
            x=1;
        }
        
        return c+x;
        
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution ob;
        long long ans = ob.countStrings(S);
        cout<<ans<<endl;
    }
    return 0;
}   // } Driver Code Ends