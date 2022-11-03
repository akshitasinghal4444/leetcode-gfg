//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& a, int k){
        //Code here
        int n=a.size();
        int i,st=0,ans=n;
        
        sort(a.begin(),a.end());
        
        for(i=0;i<n;i++)
        {
            if(a[i]-a[st]<=k)
            continue;
            
            ans=min(ans,n-i+st);
            
            while(st<=i && a[i]-a[st]>k)
            st++;
        }
        
        ans=min(ans,n-i+st);
        
        return ans;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends