// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
     vector<int> candyStore(int candies[], int n, int k)
    {
        sort(candies,candies+n);
        int i=0,j=n-1;
        vector<int> ans(2,0);
        while(i<=j){
            ans[0]+=candies[i];
            i++;j-=k;
        }
        j=0,i=n-1;
        while(j<=i){
            ans[1]+=candies[i];
            i--;j+=k;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends