//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    int i,st=-1,end=-1,j;
	    int mx=0,sum=0;
	    
	    for(i=0,j=0;i<n;i++)
	    {
	        if(a[i]<0)
	        {
	            if(sum>mx || (sum==mx && end-st+1<i-j+1))
	            {
	                mx=sum;
	                st=j;
	                end=i-1;
	            }
	            
	            j=i+1;
	            sum=0;
	        }
	        else
	        sum+=a[i];
	    }
	    
	    if(sum>mx)
	    {
	       mx=sum;
           st=j;
	       end=i-1;
	    }
	    
	    if(st==-1)
	    return {-1};
	    
	    vector<int> ans(a+st,a+end+1);
	    return ans;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends