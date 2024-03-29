//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    long long int numoffbt(long long int a[], int n){
        // Your code goes here
        int mod=1000000007;
        long long i,j,mn,mx,ans=0;
        mx=mn=a[0];

        vector<int> dp(1e5+1,0);
        
        for(i=0;i<n;i++)
        {
            mx=max(mx,a[i]);
            mn=min(mn,a[i]);
            dp[a[i]]=1;
        }

        for(i=mn;i<mx+1;i++)
        {
            if(dp[i]==0)
            continue;
            
            for(j=i+i;j/i<=i && j<=mx;j+=i)
            {
                if(dp[j]!=0 && dp[j/i]!=0)
                {
                    if(j/i==i)
                    dp[j]+=dp[i]*dp[i];
                    else
                    dp[j]+=(2*dp[i]*dp[j/i]);
                    
                    dp[j]%=mod;
                }
            }
            
            ans=(ans+dp[i])%mod;
            // cout<<i<<" "<<dp[i]<<" "<<ans<<endl; 
        }
        
        return ans;
    }
    
    /*
    long long int numoffbt(long long int a[], int n){
        // Your code goes here
        int mod=1000000007;
        long long i,j,mn,mx,ans=0;
        mx=mn=a[0];

        vector<int> dp(1e5+1,0);
        
        for(i=0;i<n;i++)
        {
            mx=max(mx,a[i]);
            mn=min(mn,a[i]);
            dp[a[i]]=1;
        }

        for(i=mn;i<mx+1;i++)
        {
            if(dp[i]!=1)
            continue;
            
            for(j=mn;j*j<=i;j++)
            {
                if(i%j==0 && dp[j]!=0 && dp[i/j]!=0)
                {
                    if(i/j==j)
                    dp[i]+=dp[j]*dp[j];
                    else
                    dp[i]+=(2*dp[j]*dp[i/j]);
                    
                    dp[i]%=mod;
                }
            }
            
            ans=(ans+dp[i])%mod;
        }
        
        return ans;
    }
    */
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<<ob.numoffbt(a,n)<<endl;
		
	}
	return 0;
}


// } Driver Code Ends