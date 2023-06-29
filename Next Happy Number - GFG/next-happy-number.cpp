//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:

    unordered_map<int,bool> m;
    
    int sum(int n)
    {
        int ans=0;
        
        while(n>0)
        {
            int x=n%10;
            n=n/10;
            
            ans+=x*x;
        }
        
        return ans;
    }
    
    bool check(int n)
    {
        if(m.find(n)==m.end())
            m[n]=check(sum(n));
        
        return m[n];
    }
    
    int nextHappy(int n){
        // code here
        n++;
        m[1]=1;
        m[2]=0;
        m[3]=0;
        
        while(!check(n))
        n++;
        
        return n;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends