//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        int l=s.length();
        int i;
        string ans="";
        stack<char> st;
        
        for(i=l-1;i>=0;i--)
        {
            if(s[i]==']' || (s[i]>='a' && s[i]<='z'))
                st.push(s[i]);
            else if(s[i]=='[')
            {
                i--;
                string t="",num="";
                while(st.top()!=']')
                {
                    t+=st.top();
                    st.pop();
                }
                st.pop();
                while(i>=0 && s[i]>='0' && s[i]<='9')
                {
                    num+=s[i];
                    i--;
                }
                i++;
                
                reverse(num.begin(),num.end());
                int n=stoi(num);
                while(n--)
                {
                    for(int j=t.length()-1;j>=0;j--)
                        st.push(t[j]);
                }
            }
        }
        
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends