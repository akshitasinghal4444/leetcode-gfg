// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int i=0;
    vector<int> ans;
    
    void toh(int src,int help,int dst,int p,int n)
    {
        if(p==0)
        return ;
        
        toh(src,dst,help,p-1,n);
        i++;
        if(i==n)
        {
            ans.push_back(src);
            ans.push_back(dst);
            return;
        }
        
        if(ans.empty())
        toh(help,src,dst,p-1,n);
    }

    vector<int> shiftPile(int p, int n){
        // code here
        toh(1,2,3,p,n);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends