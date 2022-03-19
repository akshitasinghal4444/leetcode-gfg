// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    long long findRank(string s) {
        //code here
        
        long long f[26]={0};
        long long i,n=s.length();
        
        for(i=0;i<n;i++)
        f[s[i]-'a']++;
        
        for(i=1;i<26;i++)
        f[i]+=f[i-1];
        
        long long rank=1,fact=1;
        
        for(i=2;i<=n;i++)
        fact*=i;
        
        for(i=0;i<n;i++)
        {
            long long in=s[i]-'a';
            fact=fact/(n-i);
            
            if(in>0)
            rank+=(f[in-1])*fact;
            
            while(in<26)
            {
                f[in]--;
                in++;
            }
        }
        return rank;
    }
    
    // ozebxparwklnmdqc
};

// { Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends