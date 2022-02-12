// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	    vector<string> ans;
	    string t;
	    
	    void subsequence(string s,int in,int n)
	    {
	        if(in==n)
	        {
	            if(t.size()!=0)
	            ans.push_back(t);
	            return;
	        }
	        

	        subsequence(s,in+1,n);
	        t+=s[in];
	        subsequence(s,in+1,n);
	        t.pop_back();
	    }
	
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int n=s.size();
		    ans={};
		    t="";
		    
		    subsequence(s,0,n);
		    sort(ans.begin(),ans.end());
		    
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends