// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    vector<vector<int> > subsets(vector<int>& a)
    {
        vector<vector<int>> ans;
        
        int n=a.size();
        long temp=(1<<n);
        int i,j;
        
        for(i=0;i<temp;i++)
        {
            vector<int> t;
            
            for(j=0;j<n;j++)
            {
                if(i & (1<<j))
                t.push_back(a[j]);
            }
            
            ans.push_back(t);
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
    
    /*
    vector<vector<int>> ans;
    vector<int> t;
    
    void subsets(vector<int>& a,int i)
    {
        if(i==a.size())
        {
            ans.push_back(t);
            return;
        }
        
        subsets(a,i+1);
        t.push_back(a[i]);
        subsets(a,i+1);
        t.pop_back();
    }
    
    vector<vector<int> > subsets(vector<int>& a)
    {
        //code here
        ans={};
        subsets(a,0);
        
        sort(ans.begin(),ans.end());
        return ans;
    }
    */
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}  // } Driver Code Ends