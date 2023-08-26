//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int i,n=s.length(),ans=0,begin=0;
        int f[26]={0};
        unordered_set<char> st;
        
        for(i=0;i<n;i++)
        {
            f[s[i]-'a']++;
            st.insert(s[i]);
            
            if(st.size()>k)
            {
                while(st.size()>k && begin<=i)
                {
                    if(--f[s[begin]-'a']==0)
                        st.erase(s[begin]);
                    
                    begin++;
                }
            }
            
            if(st.size()==k)
                ans=max(i-begin+1,ans);
        }
        
        return ans==0?-1:ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends