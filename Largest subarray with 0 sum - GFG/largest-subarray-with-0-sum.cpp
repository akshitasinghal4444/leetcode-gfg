//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        unordered_map<int,int> m;
        int i,s=0,ans=0;
        
        for(i=0;i<n;i++)
        {
            s+=a[i];
            
            if(s==0)
                ans=i+1;
            else if(m.find(s)==m.end())
                m[s]=i;
            else
                ans=max(ans,i-m[s]);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends