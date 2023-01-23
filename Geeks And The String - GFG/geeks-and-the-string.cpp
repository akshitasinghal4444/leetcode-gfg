//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        string ans="";
        int i,n=s.length();
        
        for(i=0;i<n;i++)
        {
            if(!ans.empty() && ans.back()==s[i])
            ans.pop_back();
            else
            ans+=s[i];
        }
        
        if(ans.empty())
        return "-1";
        
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
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends