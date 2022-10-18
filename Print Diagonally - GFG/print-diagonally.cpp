//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> a)
	{
		// Your code goes here
		vector<int> ans;
		int i,j,k;
		
		for(k=0;k<n;k++)
		{
		    for(i=0,j=k;i<n && j>=0;i++,j--)
		    ans.push_back(a[i][j]);
		}
        
        for(k=1;k<n;k++)
		{
		    for(i=k,j=n-1;i<n && j>=0;i++,j--)
		    ans.push_back(a[i][j]);
		}
        
        return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends