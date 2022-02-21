// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	
	int m=1e9+7;
	
	int CountWays(string s){
    // Code here
        int n=s.length();
		int i;
		
		if(s[0]=='0')
		return 0;
		
		vector<int> dp(n,0);
		
		dp[0]=1;
		for(i=1;i<n;i++)
		{
		    if(s[i]=='0')
		    {
		        if(s[i-1]=='1' || s[i-1]=='2')
		        dp[i]+=(i-2>=0?dp[i-2]:1);
		        else
		        return 0;
		    }
		    else
		    {
		        dp[i]=dp[i-1];
		        if(s[i-1]!='0')
		        {
		            if(stoi(s.substr(i-1,2))<=26)
		            dp[i]=(dp[i]+(i-2>=0?dp[i-2]:1))%m;
		        }
		    }
		}
		return dp[n-1];
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends