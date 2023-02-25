//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string s, string t) {
        // code here
        int i,j,ns=s.length(),nt=t.length();
        i=j=0;
        
        while(j<nt && i<ns)
        {
            if(t[j]>='A' && t[j]<='Z')
            {
                if(s[i]!=t[j])
                return 0;
                
                i++;
                j++;
            }
            else
            {
                string x="";
                
                while(j<nt && !(t[j]>='A' && t[j]<='Z'))
                x+=t[j++];
                
                i+=stoi(x);
            }
        }
        
        if(i==ns && j==nt)
        return 1;
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends