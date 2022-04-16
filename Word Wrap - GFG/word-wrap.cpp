// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
   int dp[501][2001];
   int helper(vector<int>&nums,int idx,int k,int currCount)
   {
       if(idx >= nums.size()) return 0;
       if(dp[idx][currCount]!=-1) return dp[idx][currCount];
       if(idx == nums.size()-1)
       {
           if(currCount+nums[idx] <= k) return 0;
           
           int isLeft = pow(k-currCount+1,2);
           return isLeft;
       }
       
       if(currCount+nums[idx] <= k)
       {
           int ifleft = pow(k-currCount+1,2);
           
           return dp[idx][currCount] = min(helper(nums,idx+1,k,currCount+nums[idx]+1),ifleft + helper(nums,idx+1,k,nums[idx]+1));
       }
       else
       {
           int ifleft = pow(k-currCount+1,2);
           return dp[idx][currCount] = ifleft + helper(nums,idx+1,k,nums[idx]+1);
       }
   }
   int solveWordWrap(vector<int>nums, int k) 
   { 
       // Code here
       memset(dp,-1,sizeof(dp));
       return helper(nums,0,k,0);
   } 
};



// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends