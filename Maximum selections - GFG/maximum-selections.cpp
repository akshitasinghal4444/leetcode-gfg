// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// ranges[i][0] is the start of ith range
// ranges[i][1] is the end of ith range

class Solution{
public:

    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[1]==b[1])
        return a[0]<b[0];
        
        return a[1]<b[1];
    }
    
    int max_non_overlapping( vector< vector<int> >& a )
    {
        // code here
        int n=a.size();
        int i,c=0;
        
        sort(a.begin(),a.end(),comp);
        
        int e=INT_MIN;
        for(i=0;i<n;i++)
        {
            if(a[i][0]>=e)
            {
                e=a[i][1];
                c++;
            }
        }
        return c;
    }
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

		vector< vector<int> > v(n,vector<int>(2));
		for(int i=0; i<n; i++)
			cin>> v[i][0] >> v[i][1];
			
        Solution ob;
		cout<< ob.max_non_overlapping(v) << endl;
	}
	return 1;
}

  // } Driver Code Ends