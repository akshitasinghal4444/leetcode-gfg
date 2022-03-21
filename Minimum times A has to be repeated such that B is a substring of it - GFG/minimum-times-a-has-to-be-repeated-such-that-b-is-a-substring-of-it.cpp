// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string a, string b) {
        // code here
        int na=a.length(),nb=b.length();
        int c=nb/na;
        
        string t="";
        for(int i=0;i<c;i++)
        t+=a;
        
        if(t.find(b)!=string::npos)
        return c;
        
        t+=a;
        c++;
        
        if(t.find(b)!=string::npos)
        return c;
        
        return -1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}  // } Driver Code Ends