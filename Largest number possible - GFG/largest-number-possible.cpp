//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int n, int sum){
        // code here
        //cout<<((sum%9==0)?0:1)<<endl;
        
        if((sum/9+((sum%9==0)?0:1))>n || (sum==0 && n!=1))
        return "-1";
        
        if(sum==0)
        return "0";
        
        string ans="";
        
        while(sum>=9 && n-->0)
        {
            ans+="9";
            sum-=9;
        }
        
        if(n-->0)
        {
            ans+=(sum+'0');
            sum=0;
        }
        
        while(n-->0)
            ans+="0";
            
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends