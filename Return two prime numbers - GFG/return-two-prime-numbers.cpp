// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    void findprime(vector<bool> &p,int n)
    {
        for(int i=2;i<=n;i++)
        {
            if(p[i]==0)
            {
                for(int j=2*i;j<=n;j+=i)
                p[j]=1;
            }
        }
    }

    vector<int> primeDivision(int n){
        // code here
        
        vector<bool> p(n+1,0);
        findprime(p,n);
        
        for(int i=2;i<=n;i++)
        {
            if(p[i]==0 && p[n-i]==0)
            return {i,n-i};
        }
        
        return {};
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}  // } Driver Code Ends