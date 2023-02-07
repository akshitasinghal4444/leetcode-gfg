//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &a,int n){
           //code here
           int l=1,r=1,i,j,ans=0,sl=0,sr=n-1;
           
           for(i=0,j=n-1;i<n;i++,j--)
           {
               l*=a[i];
               r*=a[j];
               
               if(l>0)
               {
                   ans=max(ans,i-sl+1);
                   l=1;
               }
               else if(l<0)
               l=-1;
               
               if(r>0)
               {
                   r=1;
                   ans=max(ans,sr-j+1);
               }
               else if(r<0)
               r=-1;
                   
               
               if(l==0)
               {
                   l=1;
                   sl=i+1;
               }
               
               
               if(r==0)
               {
                   r=1;
                   sr=j-1;
               }
           }
           
           return ans;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends