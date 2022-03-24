// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    int longest_palin_subseq(string s1)
    {
        int n=s1.length();
        int i,j;
        
        string s2=s1;
        reverse(s2.begin(),s2.end());
        
        int dp[n+1][n+1];
        
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                dp[i][j]=0;
                else if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[n][n];
    }

    int findMinInsertions(string s){
        // code here
        int lps=longest_palin_subseq(s);
        return s.length()-lps;
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends