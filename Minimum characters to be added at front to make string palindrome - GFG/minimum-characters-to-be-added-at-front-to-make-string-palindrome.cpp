//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minChar(string s){
        //Write your code here
        int n=s.length();
        string s2=s;
        int i,j;
        
        reverse(s2.begin(),s2.end());
        s+=s2;
        
        vector<int> lps(2*n,-1);
        
        for(i=1,j=-1;i<2*n;i++)
        {
            if(s[i]==s[j+1])
            {
                lps[i]=j+1;
                j++;
            }
            else if(j==-1)
                lps[i]=-1;
            else
            {
                j=lps[j];
                i--;
            }
        }
        
        return n-lps.back()-1; 
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends