// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n)
    {
        int m=1e9+7;
        long dp[n+1];
        
        for(int i=0;i<=n;i++)
        {
            if(i<=2)
            dp[i]=i;
            else
            dp[i]=(dp[i-1]+(dp[i-2]*(i-1))%m)%m;
        }
        return dp[n];
    }

    /*
    int countFriendsPairings(int n)
    {
        int m=1e9+7;
        vector<long> dp(n+1,0);
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3;i<=n;i++)
        {
            dp[i]=(dp[i-1]+dp[i-2]*(i-1))%m;
        }
        return dp[n];
    }
    */
    
    /*
    int countFriendsPairings(int n) 
    { 
        // code here
        if(n<=2)
        return n;
        
        int m=1e9+7;
        
        long f,f1,f2;
        f1=2;
        f2=1;
        int i;
        
        for(i=3;i<=n;i++)
        {
            f=(f1+((i-1)*f2)%m)%m;
            f2=f1;
            f1=f;
        }
        
        return f;
    }
    */
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends