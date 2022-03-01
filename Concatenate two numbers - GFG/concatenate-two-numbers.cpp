// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long countPairs(int n, int x, vector<int> a){
        // code here
        string s=to_string(x);
        unordered_map<string,int> m;
        int l=s.length();
        int c=0;
        
        int i,j;
        for(i=0;i<n;i++)
        m[to_string(a[i])]++;
        
        for(auto it:m)
        {
            string s1=it.first;
            int len=s1.length();
            
            if(len>l)
            continue;
            
            if(s.substr(0,len)==s1)
            {
                string s2=s.substr(len,l-len);
                if(s2==s1)
                c+=(m[s1]*(m[s1]-1));
                else if(m.find(s2)!=m.end())
                c+=(m[s1]*m[s2]);
            }
        }
        
        return c;
    }
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> numbers(N);
        for(int i=0;i<N;i++)
            cin>>numbers[i];
        Solution ob;
        long long ans = ob.countPairs(N, X, numbers);
        cout<<ans<<endl;
        
    }

    return 0; 
}  // } Driver Code Ends