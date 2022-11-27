//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> prefixCount(int n, int q, string li[], string query[])
    {
        // code here
        unordered_map<string,int> m;
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            string t="";
            
            for(char c:li[i])
            {
                t+=c;
                m[t]++;
            }
        }
        
        for(int i=0;i<q;i++)
            ans.push_back(m[query[i]]);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int Q, N, i = 0, x;
	    cin>>N;
	    string s;
	    string li[N];
	    for(int i = 0;i < N;i++)
	        cin>>li[i];
	    cin>>Q; 
	    x = Q;
	    string query[Q];
	    while(Q--){
	        cin>>s;
	        query[i++] = s;
	    }
	    
	    Solution ob;
	    vector<int> ans = ob.prefixCount(N, x, li, query);
	    for(auto i: ans) 
	        cout<<i<<"\n";
    }
    return 0;
}
// } Driver Code Ends