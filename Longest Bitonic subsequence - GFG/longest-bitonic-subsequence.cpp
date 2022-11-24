//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	vector<int> lis(vector<int> &a,int n)
	{
	    int i,j;
	    vector<int> dp(n,0);
	    dp[0]=1;
	    
	    for(i=1;i<n;i++)
	    {
	        for(j=i-1;j>=0;j--)
	        {
	            if(a[j]<a[i])
	            dp[i]=max(dp[i],dp[j]);
	        }
	        
	        dp[i]++;
	    }
	    
	    return dp;
	}
	
	int LongestBitonicSequence(vector<int> a)
	{
	    // code here
	    int n=a.size();
	    vector<int> l,r;
	    int i,j,ans=0;
	    
	    l=lis(a,n);
	    
	    reverse(a.begin(),a.end());
	    r=lis(a,n);
	    
	    reverse(a.begin(),a.end());
	    reverse(r.begin(),r.end());
	    
	   // for(i=0;i<n;i++)
	   // cout<<l[i]<<" ";
	   // cout<<endl;
	    
	   // for(i=0;i<n;i++)
	   // cout<<r[i]<<" ";
	   // cout<<endl;
	    
	    for(i=0;i<n;i++)
	    {
	        int left=0,right=0;
	        
	        for(j=i;j>=0;j--)
	            left=max(left,l[j]);
	        
	        for(j=i+1;j<n;j++)
	        {
	            if(a[j]<a[i])
	            right=max(right,r[j]);
	        }
	        
	        ans=max(ans,left+right);
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends