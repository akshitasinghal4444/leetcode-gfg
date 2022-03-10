// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    string sevenSegments(string s, int n) {
        // code here
        int segment[10]={6,2,5,5,4,5,6,3,7,5};
        int i,sum=0;
        string ans="";
        
        for(i=0;i<n;i++)
            sum+=segment[s[i]-'0'];
        
        int a[n]={0};
        for(i=0;i<n;i++)
        {
            a[i]=2;
            sum-=2;
        }
        
        for(i=0;i<n;i++)
        {
            if(sum<4)
            break;
            
            a[i]+=4;
            sum-=4;
        }
        
        a[n-1]+=sum;
        
        for(i=0;i<n;i++)
        {
            if(a[i]==6)
            ans+='0';
            else if(a[i]==2)
            ans+='1';
            else if(a[i]==3)
            ans+='7';
            else if(a[i]==4)
            ans+='4';
            else if(a[i]==5)
            ans+='2';
            else if(a[i]==7)
            ans+='8';
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        string S;
        cin>>S;

        Solution ob;
        cout << ob.sevenSegments(S,N) << endl;
    }
    return 0;
}  // } Driver Code Ends